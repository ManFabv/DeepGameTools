// Main entry point for DeepGameEngine

#define SDL_MAIN_USE_CALLBACKS 1
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "DPGameEngine/DPGameEngine.h"
#include "DPWindow/DPWindow.h"
#include <cassert>

struct AppContext
{
    SubModules::DPWindow::DPWindow dpwindow;
    DPGameEngine::Main::DPGameEngine dpgame;
};

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    auto* ctx = new AppContext();

    int init_value = ctx->dpwindow.Init();
    assert(init_value == 0);

    if (ctx->dpgame.Init(argc, argv) != 0)
    {
        delete ctx;
        return SDL_APP_FAILURE;
    }

    *appstate = ctx;
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->type == SDL_EVENT_QUIT)
    {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    if (appstate)
    {
        auto* ctx = static_cast<AppContext*>(appstate);
        delete ctx;
    }
}