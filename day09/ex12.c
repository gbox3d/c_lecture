#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>

// const int  STUDENT_MAX = 1000;
#define STUDENT_MAX 1000

int score[STUDENT_MAX][3]; //성적
char name[STUDENT_MAX][8]; //이름

int main(int argc, char *argv[])
{

  SDL_bool bLoop = SDL_TRUE;
  while (bLoop)
  {
    char _sel_menu;

    printf("1. input score \n");
    printf("2. del score \n");
    printf("3. edit score \n");
    printf("4. get total score \n");
    printf("4. get average \n");
    printf("q. quit \n");

    _sel_menu = getchar();
    rewind(stdin);
    switch (_sel_menu)
    {
    case '1':
    //lee,80,70,85
      printf("input score [name,kor,eng,math] \n");
      {
        char _tokenBuffer[32][8];
        int _tokenIndex = 0;
        int _index = 0;

        char _c;
        do {
          _c = getchar();
          printf("%c \n",_c);
          if(_c == ',') {
            _tokenBuffer[_tokenIndex][_index] = 0x00;
            _tokenIndex++;
            _index = 0;
            printf("%d \n",_tokenIndex);
          }
          else 
          {
            _tokenBuffer[_tokenIndex][_index++] = _c;
          }

        } while(_c != '\n');
        _tokenBuffer[_tokenIndex][_index] = 0x00;
        printf("%s %s %s %s \n",_tokenBuffer[0],_tokenBuffer[1],_tokenBuffer[2],_tokenBuffer[3]);
        bLoop = SDL_FALSE;
      }
      break;
    case 'q':
      bLoop = SDL_FALSE;
      break;

    default:
      break;
    }
  }

  return 0;
}
