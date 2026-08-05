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
            bool IsRunning() const;
            void PollEvents();
            void Render();

        private:
            SDL_Window* window;
            SDL_Renderer* renderer;
            bool running;
        };
    }
}
