#include "../engine/core.h"
#include "../engine/tile.h"
#include "cmd_parser.h"

// #include "layer.h"

tDE_S_Core *g_pEngineCore;

Sint16 g_WorldMap[64];
Sint16 g_AttrLayer[64];
Sint16 g_ObjLayer[64];

SDL_Texture *g_pTileSet;
SDL_Texture *g_pTileSet2;

SDL_Texture *g_pTextTxture = NULL;
SDL_Rect g_rectText; //텍스트 텍스춰 크기

SDL_Point g_PlayerPos;

int g_nGameLogicFsm = 0;

typedef struct __stage
{
  char *fileName;
  SDL_Point m_respwanPos;
  char *introMsg;

} S_Stage_Info;

S_Stage_Info g_stage_info[] = {
    {"l1.map", {1, 1}, "여기는 조용한 곳입니다."},
    {"l2.map", {1, 2}, "here is more silent room"},
    {"end", {0, 0}, "u win game"}};
int g_nCurrentStageNumber = 0;

SDL_bool keyTable[8] = {
    SDL_FALSE,
};

void doGameLogic()
{
  memset(g_ObjLayer, 0, 64 * sizeof(Uint16));
  switch (g_nGameLogicFsm)
  {
  case 0:
    printf("start game? (press key)\n");
    g_nGameLogicFsm = 1;
    g_nCurrentStageNumber = 0;
    break;
  case 1:
    if (keyTable[0]) //키가 눌러 졌는지 검사 ..
    {
      printf("u enter under-ground  ... (press key)\n");
      g_nGameLogicFsm = 2;
    }
    break;
  case 2:
    if (keyTable[0]) //키가 눌러 졌는지 검사 ..
    {
      keyTable[0] = SDL_FALSE;
      g_nGameLogicFsm = 5;
    }

    break;
  case 5:
    if (keyTable[0]) //키가 눌러 졌는지 검사 ..
    {
      keyTable[0] = SDL_FALSE;

      S_Stage_Info *pStgInfo = &g_stage_info[g_nCurrentStageNumber];
      printf("%s \n", pStgInfo->introMsg);
      static char strCmd[256];
      sprintf(strCmd,"setText %s",pStgInfo->introMsg);
      parseCmd(strCmd);

      //게임시작 준비
      Sint16 *map[2] = {g_WorldMap, g_AttrLayer};
      loadMap(pStgInfo->fileName, map);

      //플레이어 정보 초기화
      g_PlayerPos = pStgInfo->m_respwanPos;

      g_nGameLogicFsm = 10;
    }
    break;
  case 10:
  {
    SDL_Point oldPos = g_PlayerPos;
    if (keyTable[1]) //left
    {
      keyTable[1] = SDL_FALSE;
      g_PlayerPos.x--;
    }
    else if (keyTable[2]) //right
    {
      keyTable[2] = SDL_FALSE;
      g_PlayerPos.x++;
    }
    else if (keyTable[3]) //right
    {
      keyTable[3] = SDL_FALSE;
      g_PlayerPos.y--;
    }
    else if (keyTable[4]) //right
    {
      keyTable[4] = SDL_FALSE;
      g_PlayerPos.y++;
    }
    //충돌처리
    Sint16 _attr = g_AttrLayer[g_PlayerPos.x + (g_PlayerPos.y * 8)];
    if (_attr == 1 || _attr == 3) //벽
    {
      g_PlayerPos = oldPos;
    }
    else if (_attr == 2) //비상구
    {
      // g_PlayerPos = oldPos;
      //다음 스테이지로 가는 처리
      g_nGameLogicFsm = 11;
    }
    else if (_attr == 4)
    {
      for (int i = 0; i < 64; i++)
      {
        if (g_AttrLayer[i] == 3)
        {
          g_WorldMap[i] = 22;
          g_AttrLayer[i] = 2; //문으로 만들기
          break;
        }
      }
    }

    ////속성 처리
    {
      g_ObjLayer[g_PlayerPos.y * 8 + g_PlayerPos.x] = 1;
    }
  }
  break;
  case 11: //next
  {
    g_nCurrentStageNumber++;
    S_Stage_Info *pInfoStg = &g_stage_info[g_nCurrentStageNumber];
    printf("%s \n", pInfoStg->introMsg);

    if (!strcmp("end", pInfoStg->fileName))
    {
      g_nGameLogicFsm = 20;
    }
    else
    {
      g_nGameLogicFsm = 5;
    }
  }
  break;
  case 20:
  {
    printf("game over\n");
    g_nGameLogicFsm++;
  }
  break;
  case 21:
    break;
  }
}

void renderGame()
{
  SDL_SetRenderDrawColor(g_pEngineCore->m_pRender, 0x00, 0x00, 0xff, 0xff);
  SDL_RenderClear(g_pEngineCore->m_pRender);

  //월드멥 랜더링
  drawWorld(g_pEngineCore->m_pRender,
            g_pTileSet, 16, 5, 2, //타일셋 정보
            0, 0,                 //그려질 위치
            8, g_WorldMap         //월드멥 정보
  );

  //오브잭트 레이어 랜더링
  {
    Sint16 *map = g_ObjLayer;
    for (int i = 0; i < 64; i++)
    {
      Sint16 _index = map[i];
      if (_index != -1)
      {
        if (_index == 1)
        {
          //캐릭터 그리기
          int x = i % 8;
          int y = i / 8;
          putTile(g_pEngineCore->m_pRender, g_pTileSet2, x, y, 190,
                  16, 10, 2);
        }
      }
    }
  }

  //text 랜더링
  {
    if (g_pTextTxture)
    {
      g_rectText.x = 0;
      g_rectText.y = 400;

      SDL_RenderCopy(g_pEngineCore->m_pRender, g_pTextTxture, NULL, &g_rectText);
    }
  }

  SDL_RenderPresent(g_pEngineCore->m_pRender);
}

SDL_bool bLoop = SDL_TRUE;

void doEvent()
{
  static char szBuf[64];
  static Uint16 nInputFSM = 0;
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_KEYUP:
    {
      switch (nInputFSM)
      {
      case 0: //대기상태
      {
        if (event.key.keysym.sym == SDLK_SPACE)
        {
          keyTable[0] = SDL_TRUE;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
        {
          keyTable[1] = SDL_TRUE;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
        {
          keyTable[2] = SDL_TRUE;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_UP)
        {
          keyTable[3] = SDL_TRUE;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
        {
          keyTable[4] = SDL_TRUE;
        }
        else if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        {
          //bLoop = SDL_FALSE;
          parseCmd("quit");
        }
        else if (event.key.keysym.sym == SDLK_RETURN)
        {
          printf("input cmd => \n");
          nInputFSM = 1; //입력 상태로 전이
        }
      }
      break;
      case 1:
      {
        if (event.key.keysym.sym == SDLK_RETURN)
        {
          nInputFSM = 0; //대기 상태로 전이
          // printf("\n%s\n",szBuf);
          //cmd parser
          {
            parseCmd(szBuf);
          }

          szBuf[0] = 0x00; //문자열 클리어
        }
        else if (event.key.keysym.sym == SDLK_BACKSPACE)
        {
          int _len = strlen(szBuf);
          szBuf[_len - 1] = 0x00;
          printf("%s  \r", szBuf);
          fflush(stdout);
        }
      }
      break;
      }
    }
    break;
    case SDL_TEXTINPUT:
    {
      if (nInputFSM == 1)
      {
        strcat(szBuf, event.text.text);
        printf("%s  \r", szBuf);
      }
    }
    break;
    case SDL_QUIT:
      bLoop = SDL_FALSE;
      break;
    case SDL_USEREVENT:
    {
      if (!strcmp("setText", event.user.data1))
      {
        char *pMsg = (char *)event.user.data1 + 16;
        if (g_pTextTxture)
          SDL_DestroyTexture(g_pTextTxture);
        g_pTextTxture = tDE_util_createTextTexture(g_pEngineCore->m_pRender,
                                                   g_pEngineCore->m_pDefaultFont,
                                                   pMsg, &g_rectText);
      }
    }
    break;
    default:
      break;
    }
  }
}

int main(int argc, char **argv)
{
  g_PlayerPos.x = 1;
  g_PlayerPos.y = 1;

  g_pEngineCore = tDE_setup_1("game", 640, 480, 0);
  g_pTileSet = tDE_util_loadTexture(g_pEngineCore, "../res/dungeon.png");
  //10/28
  g_pTileSet2 = tDE_util_loadTexture(g_pEngineCore, "../res/gb_ft_rpg_tile_set.png");

  // loadMap("./l1.map", g_WorldMap);

  memset(g_WorldMap, -1, 64 * sizeof(Uint16));

  g_pTextTxture = tDE_util_createTextTexture(g_pEngineCore->m_pRender, g_pEngineCore->m_pDefaultFont,
                                             "게임 시작", &g_rectText);

  while (bLoop)
  {
    //게임로직
    doGameLogic();

    //랜더링
    renderGame();

    //이벤트 처리
    doEvent();
  }

  if (g_pTextTxture)
  {
    SDL_DestroyTexture(g_pTextTxture);
  }

  SDL_DestroyTexture(g_pTileSet2);
  SDL_DestroyTexture(g_pTileSet);
  tDE_closeCore(g_pEngineCore);

  return 0;
}