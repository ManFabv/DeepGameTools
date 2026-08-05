#include "DPWindow/DPWindow.h"
#include <cstdio>

SubModules::DPWindow::DPWindow::DPWindow()
    : window(nullptr)
    , renderer(nullptr)
    , running(false)
{
}

SubModules::DPWindow::DPWindow::~DPWindow()
{
    if (renderer)
    {
        SDL_DestroyRenderer(renderer);
    }

    if (window)
    {
        SDL_DestroyWindow(window);
    }

    SDL_Quit();
}

int SubModules::DPWindow::DPWindow::Init()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::fprintf(stderr, "SDL_Init failed: %s\n", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow(
        "DeepGameTools Window",
        800,
        600,
        SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
    );

    if (!window)
    {
        std::fprintf(stderr, "SDL_CreateWindow failed: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer)
    {
        std::fprintf(stderr, "SDL_CreateRenderer failed: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        window = nullptr;
        SDL_Quit();
        return -1;
    }

    running = true;
    return 0;
}

bool SubModules::DPWindow::DPWindow::IsRunning() const
{
    return running;
}

void SubModules::DPWindow::DPWindow::PollEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_EVENT_QUIT)
        {
            running = false;
        }
    }
}

void SubModules::DPWindow::DPWindow::Render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 128, 255, 255);
    SDL_FRect rect{ 100.0f, 100.0f, 600.0f, 400.0f };
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}
