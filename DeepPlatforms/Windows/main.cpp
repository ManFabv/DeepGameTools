// Main entry point for DeepGameEngine for MacOS

#include "DPGameEngine/DPGameEngine.h"

int main( int argc, char* args[] )
{
    DPGameEngine::Main::DPGameEngine dpgame;

    return dpgame.StartGame(argc, args);
}
