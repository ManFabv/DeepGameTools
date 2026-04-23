#include "DPWindow/DPWindow.h"
#include <stdexcept>

namespace SubModules
{
    namespace DPWindow
    {
        DPWindow::DPWindow(const std::string& title, int w, int h) {
            if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                throw std::runtime_error("SDL_Init fail: " + std::string(SDL_GetError()));
            }

            m_window.reset(SDL_CreateWindow(title.c_str(), w, h, SDL_WINDOW_RESIZABLE));
            if (!m_window) {
                throw std::runtime_error("Window fail: " + std::string(SDL_GetError()));
            }
            m_isOpen = true;
        }

        DPWindow::~DPWindow() {
            SDL_Quit();
        }

        void DPWindow::HandleEvent(const SDL_Event& event) {
            if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
                m_isOpen = false;
            }
        }
    }
}
