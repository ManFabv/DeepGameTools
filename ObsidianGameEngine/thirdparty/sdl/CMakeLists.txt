# CMakeList.txt : game engine third party sdl folder
#

include ( FetchContent )

FetchContent_Declare (
        sdl
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG 25f9ed87ff6947d9576fc9d79dee0784e638ac58 #2.0.16
)

FetchContent_GetProperties ( sdl )
if ( NOT sdl_POPULATED )
    message ( STATUS "Fetching sdl" )
    FetchContent_Populate ( sdl )

    set ( SDL_TEST OFF CACHE INTERNAL "Run sdl tests" )
    set ( SDL_SUBSYSTEMS Video Events Joystick Haptic )

    add_subdirectory ( ${sdl_SOURCE_DIR} ${sdl_BINARY_DIR} )
endif ()
