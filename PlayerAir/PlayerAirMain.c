﻿#include <stdio.h>

#include "PlayerAirFFMpeg.h"
#include "PlayerAirLog.h"
#include "PlayerAirSDL.h"

static void PlayerAirDisplay(void);

int main(int argc, char** argv)
{
    PlayerAirLogFunctionStart("");

    SDL_Init(SDL_INIT_EVERYTHING);

	if (PlayerAirFFMpegInit() < 0)
	{
        PlayerAirLogCritical("fail to PlayerAirFFMpegInit()");
        PlayerAirLogFunctionEnd("");
		return -1;
	}

	if (PlayerAirSDLInit(PlayerAirFFMpegWidth(), PlayerAirFFMpegHeight()) < 0)
	{
        PlayerAirLogCritical("fail to PlayerAirSDLInit(PlayerAirFFMpegWidth(), PlayerAirFFMpegHeight())");
        PlayerAirLogFunctionEnd("");
		return -1;
	}

    SDL_Event event;
    uint32_t windowID = SDL_GetWindowID(sdl->screen);
    int running = 1;
    while (running)
    {
        if (PlayerAirFFMpegUpdateFrame() == 0)
        {
            PlayerAirDisplay();

            
        }

        while (SDL_PollEvent(&event))
        {
            switch (event.type) {
            case SDL_WINDOWEVENT:
                if (event.window.windowID == windowID) {
                    switch (event.window.event) {
                    case SDL_WINDOWEVENT_CLOSE: {
                        event.type = SDL_QUIT;
                        running = 0;
                        SDL_PushEvent(&event);
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

    PlayerAirLogFunctionEnd("");
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
