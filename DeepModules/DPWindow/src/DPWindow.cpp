#include "DPWindow/DPWindow.h"

SubModules::DPWindow::DPWindow::DPWindow()
{
}

SubModules::DPWindow::DPWindow::~DPWindow()
{
    Shutdown();
}

int SubModules::DPWindow::DPWindow::Init()
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        SDL_Log("Error al inicializar SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    m_window = SDL_CreateWindow("DeepGameEngine", 1280, 720, SDL_WINDOW_RESIZABLE);
    if (!m_window)
    {
        SDL_Log("Error al crear la ventana: %s", SDL_GetError());
        SDL_Quit();
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}

void SubModules::DPWindow::DPWindow::Shutdown()
{
    if (m_window)
    {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
    SDL_Quit();
}