#pragma once
#include "DPWindow/DPWindow.h"
#include "Core/Components.hpp"
#include <entt/entt.hpp>

namespace Core {

class Game {
public:
    // RAII: Lista de inicialización
    Game(const std::string& title, int w, int h);
    ~Game() = default;

    void run();

private:
    void processEvents();
    void update();
    void render();

private:
    SubModules::DPWindow::DPWindow m_window; 
    entt::registry m_registry;
    bool m_isRunning;
};

}
