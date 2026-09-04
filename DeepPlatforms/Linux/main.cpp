// Main entry point for DeepGameEngine for Linux

#include "DPGameEngine/DPGameEngine.h"

#include "DPGameEngine/DPGameEngine.h"
#include "DPWindow/DPWindow.h"
#include <cassert>

int main( int argc, char* args[] )
{
    SubModules::DPWindow::DPWindow dpwindow;
    int init_value = dpwindow.Init();
    assert(init_value == 0);

    DPGameEngine::Main::DPGameEngine dpgame;
    return dpgame.Init(argc, args);
}