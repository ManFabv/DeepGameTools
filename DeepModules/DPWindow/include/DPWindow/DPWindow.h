#pragma once

#include <SDL3/SDL.h>

namespace SubModules
{
    namespace DPWindow
    {
        class DPWindow
        {
        public:
            DPWindow();
            ~DPWindow();

            int Init();
            void Shutdown();

            SDL_Window* GetNativeWindow() const { return m_window; }

        private:
            SDL_Window* m_window{nullptr};
        };
    }
}
