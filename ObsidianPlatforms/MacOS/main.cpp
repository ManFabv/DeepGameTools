// Main entry point for ObsidianGameEngine for MacOS

#include "OGameEngine/OGameEngine.h"

int main( int argc, char* args[] )
{
    OGameEngine::Main::OGameEngine ogame;

    return ogame.StartGame(argc, args);
}
