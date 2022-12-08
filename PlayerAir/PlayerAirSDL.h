#ifndef   __NOVEMBERIZING_PLAYER_AIR__SDL__H__
#define   __NOVEMBERIZING_PLAYER_AIR__SDL__H__

#include <SDL.h>

struct PlayerAirSDL;

typedef struct PlayerAirSDL PlayerAirSDL;

struct PlayerAirSDL
{
    SDL_Window* screen;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect rect;
};

extern PlayerAirSDL * sdl;

extern int PlayerAirSDLInit(int width, int height);

extern void PlayerAirSDLDisplay(const Uint8* Yplane, int Ypitch, const Uint8* Uplane, int Upitch, const Uint8* Vplane, int Vpitch);

#endif // __NOVEMBERIZING_PLAYER_AIR__SDL__H__
