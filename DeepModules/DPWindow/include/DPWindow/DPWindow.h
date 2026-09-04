#pragma once

struct SDL_Window;

namespace SubModules::DPWindow
{
    class DPWindow
    {
    public:
        DPWindow() = default;
        ~DPWindow();

        DPWindow(const DPWindow&) = delete;
        DPWindow& operator=(const DPWindow&) = delete;

        DPWindow(DPWindow&& other) noexcept;
        DPWindow& operator=(DPWindow&& other) noexcept;

        bool Init();
        void Shutdown();

        [[nodiscard]] SDL_Window* GetNativeWindow() const { return m_window; }

    private:
        SDL_Window* m_window{nullptr};
    };
}