// Deep Game Engine main entry point

#include "DPGameEngine/DPGameEngine.h"
#include "Core/Game.hpp"
#include <iostream>

int DPGameEngine::Main::DPGameEngine::StartGame ( int argc, char* args[] )
{
    try {
        Core::Game game("DeepGameTools", 1280, 720);
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
