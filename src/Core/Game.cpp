#include "Core/Game.hpp"
#include <iostream>

namespace Core {

Game::Game(const std::string& title, int w, int h)
    : m_window(title, w, h), m_isRunning(true) {
    // Inicializar entidad de prueba con EnTT
    auto entity = m_registry.create();
    m_registry.emplace<Position>(entity, 0.0f, 0.0f);
    m_registry.emplace<Velocity>(entity, 1.0f, 0.5f);
    
    std::cout << "ECS: Entidad de prueba creada con éxito." << std::endl;
}

void Game::run() {
    while (m_isRunning && m_window.IsOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        m_window.HandleEvent(event);

        if (event.type == SDL_EVENT_QUIT) {
            m_isRunning = false;
        }

        // Abstracción de Input: Cerrar con Escape
        if (event.type == SDL_EVENT_KEY_DOWN) {
            if (event.key.key == SDLK_ESCAPE) {
                m_isRunning = false;
            }
        }
    }
}

void Game::update() {
    // Lógica de movimiento con EnTT
    auto view = m_registry.view<Position, Velocity>();
    
    for (auto entity : view) {
        auto& pos = view.get<Position>(entity);
        const auto& vel = view.get<Velocity>(entity);
        
        pos.x += vel.vx;
        pos.y += vel.vy;
        
        // Log periódico cada X iteraciones (para no saturar la consola)
        static int frameCount = 0;
        if (++frameCount % 100 == 0) {
            std::cout << "ECS Update: Posición[" << pos.x << ", " << pos.y << "]" << std::endl;
        }
    }
}

void Game::render() {
    // Lógica de renderizado aquí
}

}
