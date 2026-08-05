// Deep Game Engine main entry point

#include "DPGameEngine/DPGameEngine.h"
#include <iostream>

#include "DPWindow/DPWindow.h"

int DPGameEngine::Main::DPGameEngine::StartGame ( int argc, char* args[] )
{
    SubModules::DPWindow::DPWindow dpwindow;

    int init_value = dpwindow.Init();
    if (init_value != 0)
    {
        std::cerr << "DPWindow initialization failed with code " << init_value << std::endl;
        return init_value;
    }

    while (dpwindow.IsRunning())
    {
        dpwindow.PollEvents();
        dpwindow.Render();
    }

    return 0;
}
