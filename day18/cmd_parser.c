#include "../engine/core.h"

#define MAX_TOKEN_SIZE 32

extern Sint16 g_worldMap_Layer_1[];

int doTokenize(char *szBuf, char (*szBufToken)[MAX_TOKEN_SIZE])
{
  //change 10
  //[change,10]
  char *szpTemp;
  char *pNextToken = NULL;
  const char *pszDelimiter = " ";
  szpTemp = strtok(szBuf, pszDelimiter);

  int _nTokenIndex = 0;
  while (szpTemp != NULL)
  {
    strcpy(szBufToken[_nTokenIndex],szpTemp);
    _nTokenIndex++;
    szpTemp = strtok(NULL, pszDelimiter);
  }
  return _nTokenIndex;
}

void parseCmd(char *_szCmd)
{
  static char szCmd[64];
  static char szTokens[8][32];

  strcpy(szCmd,_szCmd);

  printf("token count %s\n",szCmd);
  int _numToken = doTokenize(szCmd, szTokens);

  printf("token count %d\n",_numToken);

  if (strcmp(szTokens[0], "quit") == 0)
  {
    SDL_Event evt;
    evt.type = SDL_QUIT;
    evt.quit.timestamp = SDL_GetTicks();
    SDL_PushEvent(&evt);
    
  }
  // else if (strcmp(szTokens[0], "setTile") == 0)
  // {
  //   //setTile x y index
  //   int _x = SDL_atoi(szTokens[1]);
  //   int _y = SDL_atoi(szTokens[2]);
  //   int _index = SDL_atoi(szTokens[3]);

  //   g_worldMap_Layer_1[(_y * 8) + _x] = _index;
  // }
  else if (strcmp(szTokens[0], "save") == 0)
  {
    //save file.map
    char *pFileName = szTokens[1];
    SDL_RWops *rw = SDL_RWFromFile(pFileName, "wb");
    SDL_RWwrite(rw, g_worldMap_Layer_1, sizeof(Uint16), 64);
    SDL_RWclose(rw);
  }
  else if (strcmp(szTokens[0], "load") == 0)
  {
    char *pFileName = szTokens[1];
    SDL_RWops *rw = SDL_RWFromFile(pFileName, "rb");
    SDL_RWread(rw, g_worldMap_Layer_1, sizeof(Uint16), 64);
    SDL_RWclose(rw);
  }
  else if (strcmp(szTokens[0], "new") == 0)
  {
    memset(g_worldMap_Layer_1,-1,128);
  }
}