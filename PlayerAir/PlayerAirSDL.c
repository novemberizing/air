#include <stdio.h>

#include "PlayerAirSDL.h"

PlayerAirSDL * sdl = NULL;

extern int PlayerAirSDLInit(int width, int height)
{
    if (sdl == NULL)
    {
        sdl = (PlayerAirSDL*)calloc(1, sizeof(PlayerAirSDL));

        sdl->screen = SDL_CreateWindow("NOVEMBERIZING PLAYER AIR", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
        sdl->renderer = SDL_CreateRenderer(sdl->screen, -1, SDL_RENDERER_ACCELERATED);
        sdl->texture = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING | SDL_TEXTUREACCESS_TARGET, width, height);
        sdl->rect.x = 0;
        sdl->rect.y = 0;
        sdl->rect.w = width;
        sdl->rect.h = height;
        // SDL_SetWindowPosition(sdl->screen, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        // SDL_SetWindowSize(sdl->screen, (width / 8) * 3, (height / 8) * 3);
    }

    return 0;
}