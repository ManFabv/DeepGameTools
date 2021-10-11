// Deep Game Engine main entry point

#include "DPGameEngine/DPGameEngine.h"
#include "vulkan/vulkan.h"
#include <cassert>

#include "DPWindow/DPWindow.h"

int DPGameEngine::Main::DPGameEngine::StartGame ( int argc, char* args[] )
{
    SubModules::DPWindow::DPWindow dpwindow;

    int init_value = dpwindow.Init();

    assert(init_value == 0);

    return 0;
}
