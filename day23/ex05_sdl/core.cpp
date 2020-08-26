#include "core.h"
#include <time.h>

tDE_S_Core *tDE_setup_1(const char *szTitle, int window_width, int window_height, Uint32 flags)
{
  if (SDL_Init(SDL_INIT_EVERYTHING))
  {
    printf("sdl init error : %s \n", SDL_GetError());
    return NULL;
  }

  tDE_S_Core *pCore = (tDE_S_Core*)SDL_malloc(sizeof(tDE_S_Core));

  pCore->m_pWin = SDL_CreateWindow(szTitle,
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   window_width, window_height, flags);
  pCore->m_ScreenWidth = window_width;
  pCore->m_ScreenHeight = window_height;

  pCore->m_pRender = SDL_CreateRenderer(pCore->m_pWin, -1, SDL_RENDERER_ACCELERATED);
  if (!IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)
  {
    printf("sdl_image dll init error : %s \n", SDL_GetError());
    return NULL;
  }
  if (TTF_Init() == -1)
  {
    printf("sdl_ttf dll init error : %s \n", SDL_GetError());
    return NULL;
  }

  pCore->m_pDefaultFont = TTF_OpenFont("../res/nmf.ttf", 14);
  if (!pCore->m_pDefaultFont)
  {
    printf("load default font error : %s\n", SDL_GetError());
  }

  printf("init module ok \n");
  printf("engine start at %8d\n", time(NULL));
  srand(time(NULL));

  return pCore;
}

void tDE_closeCore(tDE_S_Core *pCore)
{
  TTF_CloseFont(pCore->m_pDefaultFont);
  SDL_DestroyRenderer(pCore->m_pRender);
  SDL_DestroyWindow(pCore->m_pWin);
}

SDL_Texture *tDE_util_loadTexture(tDE_S_Core *pCore, const char *filename)
{
  SDL_Surface *surface;
  surface = IMG_Load(filename);

  if (surface == NULL)
  {
    printf("file load error : %s\n", SDL_GetError());
    return NULL;
  }
  else
  {
    printf("load success %s\n", filename);
  }
  SDL_Texture *pTex = SDL_CreateTextureFromSurface(pCore->m_pRender, surface);
  SDL_FreeSurface(surface);
  return pTex;
}

SDL_bool tDE_util_parseSheet(char *szStr, tDE_S_SheetData *pData)
{

  // FILE *fp = fopen("../res/tanks/sheet_tanks.xml", "rt");

  // char *szStr;

  char *szToken = strtok(szStr, " ");
  if (!strcmp(szToken, "\t<SubTexture"))
  {
    static char _szBuf[5][256];
    //name
    szToken = strtok(NULL, " ");
    strcpy(_szBuf[0], szToken);
    //x
    szToken = strtok(NULL, " ");
    strcpy(_szBuf[1], szToken);
    //y
    szToken = strtok(NULL, " ");
    strcpy(_szBuf[2], szToken);
    //w
    szToken = strtok(NULL, " ");
    strcpy(_szBuf[3], szToken);
    //h
    szToken = strtok(NULL, " ");
    strcpy(_szBuf[4], szToken);

    //name 파싱
    szToken = strtok(_szBuf[0], "=");
    szToken = strtok(NULL, ".");
    strcpy(_szBuf[0], szToken + 1);
    //printf("%s\n", _szBuf[0]);
    strcpy(pData->szName, _szBuf[0]);

    //x 파싱
    szToken = strtok(_szBuf[1], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("x:%d\n", atoi(szToken));
    pData->m_area.x = atoi(szToken);

    //y 파싱
    szToken = strtok(_szBuf[2], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("y:%d\n", atoi(szToken));
    pData->m_area.y = atoi(szToken);

    //w
    szToken = strtok(_szBuf[3], "\"");
    szToken = strtok(NULL, "\"");
    // strcpy(_szBuf[1],szToken+1);
    // printf("w:%d\n", atoi(szToken));
    pData->m_area.w = atoi(szToken);

    //h
    szToken = strtok(_szBuf[4], "\"");
    szToken = strtok(NULL, "\"");
    pData->m_area.h = atoi(szToken);
    return SDL_TRUE;
  }
  return SDL_FALSE;

  //fclose(fp);
}

SDL_Texture *tDE_util_createTextTexture(SDL_Renderer *pRenderer,
                                        TTF_Font *pFont, const char *text,
                                        SDL_Rect *ptextRect)
{

  // const Uint16 *text = L"게임 시작";
  SDL_Color _whiteColor = {0xff, 0xff, 0xff, 0xff};
  SDL_Surface *textSurface = TTF_RenderUTF8_Solid(pFont, text, _whiteColor);
  SDL_Texture *ptex = SDL_CreateTextureFromSurface(pRenderer, textSurface);

  ptextRect->w = textSurface->w;
  ptextRect->h = textSurface->h;

  SDL_FreeSurface(textSurface);

  // g_pTextTxture = ptex;
  return ptex;
}