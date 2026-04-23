#include "Core/Game.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        Core::Game app("DeepGameTools", 1280, 720);
        app.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}
