#ifndef   _CRT_SECURE_NO_WARNINGS
#define   _CRT_SECURE_NO_WARNINGS
#endif // _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "PlayerAirFFMpeg.h"
#include "PlayerAirLog.h"
#include "PlayerAirSDL.h"

static void PlayerAirDisplay(void);

static void PlayerAirFFMpegLogFunc(void* context, int level, const char* format, va_list ap)
{
    vprintf(format, ap);
}

int main(int argc, char** argv)
{
    PlayerAirLogFunctionStart("");

    // av_log_set_level(AV_LOG_TRACE);
    // av_log_set_callback(PlayerAirFFMpegLogFunc);

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

    char buffer[1024];
    SDL_Event event;
    uint32_t windowID = SDL_GetWindowID(sdl->screen);
    SDL_MouseMotionEvent motion;
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
            case SDL_MOUSEBUTTONDOWN:
                printf("mouse button down %d, %d\r\n", (int)((double) event.motion.x * 8.0f / 3.0f), (int) ((double) event.motion.y * 8.0f / 3.0f));
                sprintf(buffer, "adb shell input tap %d %d", (int)((double)event.motion.x * 8.0f / 3.0f), (int)((double)event.motion.y * 8.0f / 3.0f));
                system(buffer);
                break;
            case SDL_KEYDOWN:
                printf("event.key.keysym.sym => %d\r\n", event.key.keysym.sym);
                switch (event.key.keysym.sym)
                {
                case SDLK_a: system("adb shell input keyevent 29"); break;
                case SDLK_b: system("adb shell input keyevent 30"); break;
                case SDLK_c: system("adb shell input keyevent 31"); break;
                case SDLK_d: system("adb shell input keyevent 32"); break;
                case SDLK_e: system("adb shell input keyevent 33"); break;
                case SDLK_f: system("adb shell input keyevent 34"); break;
                case SDLK_g: system("adb shell input keyevent 35"); break;
                case SDLK_h: system("adb shell input keyevent 36"); break;
                case SDLK_i: system("adb shell input keyevent 37"); break;
                case SDLK_j: system("adb shell input keyevent 38"); break;
                case SDLK_k: system("adb shell input keyevent 39"); break;
                case SDLK_l: system("adb shell input keyevent 40"); break;
                case SDLK_m: system("adb shell input keyevent 41"); break;
                case SDLK_n: system("adb shell input keyevent 42"); break;
                case SDLK_o: system("adb shell input keyevent 43"); break;
                case SDLK_p: system("adb shell input keyevent 44"); break;
                case SDLK_q: system("adb shell input keyevent 45"); break;
                case SDLK_r: system("adb shell input keyevent 46"); break;
                case SDLK_s: system("adb shell input keyevent 47"); break;
                case SDLK_t: system("adb shell input keyevent 48"); break;
                case SDLK_u: system("adb shell input keyevent 49"); break;
                case SDLK_v: system("adb shell input keyevent 50"); break;
                case SDLK_w: system("adb shell input keyevent 51"); break;
                case SDLK_x: system("adb shell input keyevent 52"); break;
                case SDLK_y: system("adb shell input keyevent 53"); break;
                case SDLK_z: system("adb shell input keyevent 54"); break;
                }
                break;
            case SDL_MOUSEMOTION:
                memcpy(&motion, &event.motion, sizeof(SDL_MouseMotionEvent));
                break;
            case SDL_MOUSEWHEEL:
                if (event.wheel.y > 0)
                {
                    printf("mouse wheel up\r\n");
                    int x = (int)((double)motion.x * 8.0f / 3.0f);
                    int y = (int)((double)motion.y * 8.0f / 3.0f);
                    sprintf(buffer, "adb shell input touchscreen swipe %d %d %d %d", x, y, x, y + 500);
                    printf("%s\r\n", buffer);
                    system(buffer);
                }
                else if (event.wheel.y < 0)
                {
                    printf("mouse wheel down\r\n");
                    int x = (int)((double)motion.x * 8.0f / 3.0f);
                    int y = (int)((double)motion.y * 8.0f / 3.0f);
                    sprintf(buffer, "adb shell input touchscreen swipe %d %d %d %d", x, y, x, y - 500);
                    printf("%s\r\n", buffer);
                    system(buffer);
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
