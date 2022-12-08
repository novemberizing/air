﻿#include <stdio.h>

#include "PlayerAirFFMpeg.h"
#include "PlayerAirSDL.h"

static void PlayerAirDisplay(void);

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

	if (PlayerAirFFMpegInit() < 0)
	{
		printf("fail to PlayerAirFFMpegInit()\r\n");
		return -1;
	}

	if (PlayerAirSDLInit(PlayerAirFFMpegWidth(), PlayerAirFFMpegHeight()) < 0)
	{
		printf("fail to PlayerAirSDLInit(PlayerAirFFMpegWidth(), PlayerAirFFMpegHeight())\r\n");
		return -1;
	}

    SDL_Event evt;
    uint32_t windowID = SDL_GetWindowID(sdl->screen);
    int running = 1;
    while (running)
    {
        if (PlayerAirFFMpegUpdateFrame() == 0)
        {
            PlayerAirDisplay();

            while (SDL_PollEvent(&evt))
            {
                switch (evt.type) {
                case SDL_WINDOWEVENT:
                    if (evt.window.windowID == windowID) {
                        switch (evt.window.event) {
                        case SDL_WINDOWEVENT_CLOSE: {
                            evt.type = SDL_QUIT;
                            running = 0;
                            SDL_PushEvent(&evt);
                            break;
                        }
                        };
                    }
                    break;
                case SDL_QUIT:
                    running = 0;
                    break;
                }
            }
        }
    }

	return 0;
}

static void PlayerAirDisplay(void)
{
    SDL_UpdateYUVTexture(sdl->texture, &sdl->rect, ffmpeg->frame->data[0], ffmpeg->frame->linesize[0], ffmpeg->frame->data[1], ffmpeg->frame->linesize[1], ffmpeg->frame->data[2], ffmpeg->frame->linesize[2]);
    SDL_RenderSetScale(sdl->renderer, 0.375, 0.375);
    SDL_RenderClear(sdl->renderer);
    SDL_RenderCopy(sdl->renderer, sdl->texture, NULL, &sdl->rect);
    SDL_RenderPresent(sdl->renderer);
}
