#include "DPWindow/DPWindow.h"
#include <SDL3/SDL.h>

namespace SubModules::DPWindow
{
    DPWindow::~DPWindow()
    {
        Shutdown();
    }

    DPWindow::DPWindow(DPWindow&& other) noexcept
        : m_window(other.m_window)
    {
        other.m_window = nullptr;
    }

    DPWindow& DPWindow::operator=(DPWindow&& other) noexcept
    {
        if (this != &other)
        {
            Shutdown();
            m_window = other.m_window;
            other.m_window = nullptr;
        }
        return *this;
    }

    bool DPWindow::Init()
    {
        m_window = SDL_CreateWindow("DeepGameEngine", 1280, 720, SDL_WINDOW_RESIZABLE);
        if (!m_window)
        {
            return false;
        }
        return true;
    }

    void DPWindow::Shutdown()
    {
        if (m_window)
        {
            SDL_DestroyWindow(m_window);
            m_window = nullptr;
        }
    }
}