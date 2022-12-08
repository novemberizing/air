#include <stdio.h>

#include "PlayerAirSDL.h"

PlayerAirSDL * sdl = NULL;

extern int PlayerAirSDLInit(int width, int height)
{
    if (sdl == NULL)
    {
        sdl = (PlayerAirSDL*)calloc(1, sizeof(PlayerAirSDL));

//        width = (width / 8) * 3;
//        height = (height / 8) * 3;

        sdl->screen = SDL_CreateWindow("NOVEMBERIZING PLAYER AIR", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, (width / 8) * 3, (height / 8) * 3, SDL_WINDOW_RESIZABLE);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
        sdl->renderer = SDL_CreateRenderer(sdl->screen, -1, SDL_RENDERER_ACCELERATED);
        sdl->texture = SDL_CreateTexture(sdl->renderer, SDL_PIXELFORMAT_IYUV, SDL_TEXTUREACCESS_STREAMING | SDL_TEXTUREACCESS_TARGET, width, height);
        sdl->rect.x = 0;
        sdl->rect.y = 0;
        sdl->rect.w = width;
        sdl->rect.h = height;
    }

    return 0;
}