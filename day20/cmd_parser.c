#include "../engine/core.h"

#define MAX_TOKEN_SIZE 32

static char pMsgBuf[256];

int doTokenize(char *szBuf, char (*szBufToken)[MAX_TOKEN_SIZE])
{
  char *szpTemp;
  char *pNextToken = NULL;
  const char *pszDelimiter = " ";
  szpTemp = strtok(szBuf, pszDelimiter);

  int _nTokenIndex = 0;
  while (szpTemp != NULL)
  {
    strcpy(szBufToken[_nTokenIndex], szpTemp);
    _nTokenIndex++;
    szpTemp = strtok(NULL, pszDelimiter);
  }
  return _nTokenIndex;
}

void parseCmd(char *_szCmd)
{
  static char szCmd[64];
  static char szTokens[8][32];

  strcpy(szCmd, _szCmd);

  printf("token count %s\n", szCmd);
  int _numToken = doTokenize(szCmd, szTokens);

  printf("token count %d\n", _numToken);

  if (strcmp(szTokens[0], "quit") == 0)
  {
    SDL_Event evt;
    evt.type = SDL_QUIT;
    evt.quit.timestamp = SDL_GetTicks();
    SDL_PushEvent(&evt);
  }
  else if (strcmp(szTokens[0], "save") == 0)
  {
    //save file.map
    char *pFileName = szTokens[1];
    // SDL_RWops *rw = SDL_RWFromFile(pFileName, "wb");
    // SDL_RWwrite(rw, g_worldMap_Layer[0], sizeof(Uint16), 64);
    // SDL_RWclose(rw);

    // static char pMsg[32];
    strcpy(pMsgBuf, "save");
    strcpy(pMsgBuf + 16, pFileName);
    SDL_Event evt;
    evt.type = SDL_USEREVENT;
    evt.user.data1 = pMsgBuf;
    evt.user.timestamp = SDL_GetTicks();
    SDL_PushEvent(&evt);
  }
  else if (strcmp(szTokens[0], "load") == 0)
  {
    char *pFileName = szTokens[1];
    // static char pMsg[32];
    strcpy(pMsgBuf, "load");
    strcpy(pMsgBuf + 16, pFileName);
    SDL_Event evt;
    evt.type = SDL_USEREVENT;
    evt.user.data1 = pMsgBuf;
    evt.user.timestamp = SDL_GetTicks();
    SDL_PushEvent(&evt);

    // SDL_RWops *rw = SDL_RWFromFile(pFileName, "rb");
    // SDL_RWread(rw, g_worldMap_Layer[0], sizeof(Uint16), 64);
    // SDL_RWclose(rw);
  }
  else if (strcmp(szTokens[0], "new") == 0)
  {
    // memset(g_worldMap_Layer[0],-1,128);
    // static char *pMsg = "new";
    strcpy(pMsgBuf, szTokens[0]);
    SDL_Event evt;
    evt.type = SDL_USEREVENT;
    evt.user.data1 = pMsgBuf;
    evt.user.timestamp = SDL_GetTicks();
    SDL_PushEvent(&evt);
  }
  else if (strcmp(szTokens[0], "brush") == 0) //brush change (attr)
  {
    strcpy(pMsgBuf, szTokens[0]);
    Uint16 cmd = 0;
    Uint16 value = 0;

    if (strcmp(szTokens[1], "change") == 0)
    {
      cmd = 1;
      value = atoi(szTokens[2]);
    }
    else if(strcmp(szTokens[1], "next") == 0)
    {
      cmd=2;
    }
    else if(strcmp(szTokens[1], "prev") == 0)
    {
      cmd=3;
    }

    memcpy(pMsgBuf + 16, (Uint16 *)&cmd, 2);
    memcpy(pMsgBuf + 18, (Uint16 *)&value, 2);

    SDL_Event evt;
    evt.type = SDL_USEREVENT;
    evt.user.data1 = pMsgBuf;
    evt.user.timestamp = SDL_GetTicks();

    SDL_PushEvent(&evt);
  }
}