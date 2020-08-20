#include "../engine/core.h"
#include "../engine/tile.h"
#include "cmd_parser.h"

// #include "layer.h"

tDE_S_Core *g_pEngineCore;

Sint16 g_WorldMap[4][64];

SDL_Texture *g_pTileSet;
SDL_Texture *g_pTileSet2;

SDL_Point g_PlayerPos;

int g_nGameLogicFsm = 0;

int main(int argc, char **argv)
{
  g_PlayerPos.x = 1;
  g_PlayerPos.y = 1;

  g_pEngineCore = tDE_setup_1("game", 640, 480, 0);
  g_pTileSet = tDE_util_loadTexture(g_pEngineCore, "../res/dungeon.png");
  //10/28
  g_pTileSet2 = tDE_util_loadTexture(g_pEngineCore, "../res/gb_ft_rpg_tile_set.png");

  // loadMap("./l1.map", g_WorldMap);

  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    SDL_SetRenderDrawColor(g_pEngineCore->m_pRender, 0x00, 0x00, 0xff, 0xff);
    SDL_RenderClear(g_pEngineCore->m_pRender);

    switch (g_nGameLogicFsm)
    {
    case 0:
      printf("start game? (press key)\n");
      g_nGameLogicFsm = 1;      
      break;
    case 1:
      break;
    case 10:
    {
      //월드멥 그리기
      drawWorld(g_pEngineCore->m_pRender,
                g_pTileSet, 16, 5, 2, //타일셋 정보
                0, 0,                 //그려질 위치
                8, g_WorldMap[0]         //월드멥 정보
      );
    }
    break;
    }
    SDL_RenderPresent(g_pEngineCore->m_pRender);

    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_KEYUP:
      {       
      }
      break;
      case SDL_QUIT:
        bLoop = SDL_FALSE;
        break;

      default:
        break;
      }
    }
  }

  SDL_DestroyTexture(g_pTileSet);
  tDE_closeCore(g_pEngineCore);

  return 0;
}