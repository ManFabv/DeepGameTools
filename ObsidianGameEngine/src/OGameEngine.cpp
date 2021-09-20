// Obsidian Game Engine main entry point

#include "OGameEngine/OGameEngine.h"
#include <SDL.h>
#include "vulkan/vulkan.h"
#include <cassert>

#include "OWindow/OWindow.h"

int OGameEngine::Main::OGameEngine::StartGame ( int argc, char* args[] )
{
    SubModules::OWindow::OWindow owindow;

    SDL_Window* window = nullptr;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = nullptr;

    //Initialize SDL
    int sdl_init_result = SDL_Init( SDL_INIT_VIDEO );
    
    assert( sdl_init_result >= 0 );

    //Create window
    window = SDL_CreateWindow( "Obsidian Game Engine Tools", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
    
    assert( window != nullptr );
    
    //Get window surface
    screenSurface = SDL_GetWindowSurface( window );

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

        //Fill the surface white
        SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );
        
        //Update the surface
        SDL_UpdateWindowSurface( window );
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}
