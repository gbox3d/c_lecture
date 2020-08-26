// ex05_sdl.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "core.h"

SDL_Window* g_pWindow;
SDL_Renderer* g_pRenderer;
SDL_Texture* g_pTexture;


int main(int argc, char* argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    { 
        printf("init error \n");
        return 1;
    }
    g_pWindow = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        640, 480, 0
    );
    g_pRenderer = SDL_CreateRenderer(g_pWindow,-1,SDL_RENDERER_ACCELERATED);

    
    {
            SDL_Surface* surface;
            surface = IMG_Load("..\\..\\res\\tanks\\sheet_tanks.png");

            if (surface == NULL)
            {
                printf("file load error : %s\n", SDL_GetError());
                return NULL;
            }
            else
            {
                
            }
            SDL_Texture* pTex = SDL_CreateTextureFromSurface(g_pRenderer, surface);
            SDL_FreeSurface(surface);
            g_pTexture = pTex;
    }

    static SDL_bool bLoop = SDL_TRUE;
    while (bLoop)
    {
        {
            SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 0xff);
            SDL_RenderClear(g_pRenderer);

            SDL_Rect srcRt = { 0, 0, 64, 64 };
            SDL_Rect destRt = { 200, 200, 64, 64 };

            SDL_RenderCopy(g_pRenderer, g_pTexture, &srcRt, &destRt);

            SDL_RenderPresent(g_pRenderer);
        }
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                bLoop = SDL_FALSE;
                break;
            }
        }
    }

    SDL_DestroyRenderer(g_pRenderer);
    SDL_DestroyWindow(g_pWindow);

    return 0;
}
