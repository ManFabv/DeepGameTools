// Obsidian Game Engine main entry point

#include "OGameEngine/OGameEngine.h"
#include "vulkan/vulkan.h"
#include <cassert>

#include "OWindow/OWindow.h"

int OGameEngine::Main::OGameEngine::StartGame ( int argc, char* args[] )
{
    SubModules::OWindow::OWindow owindow;

    int init_value = owindow.Init();

    assert(init_value == 0);

    return 0;
}
