#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <string>

namespace SubModules
{
    namespace DPWindow
    {
        struct SDLWindowDeleter {
            void operator()(SDL_Window* w) const { if (w) SDL_DestroyWindow(w); }
        };

        using WindowPtr = std::unique_ptr<SDL_Window, SDLWindowDeleter>;

        class DPWindow
        {
        public:
            DPWindow(const std::string& title, int w, int h);
            ~DPWindow();

            void HandleEvent(const SDL_Event& event);
            bool IsOpen() const { return m_isOpen; }
            SDL_Window* GetRawWindow() const { return m_window.get(); }

        private:
            WindowPtr m_window;
            bool m_isOpen = false;
        };
    }
}
