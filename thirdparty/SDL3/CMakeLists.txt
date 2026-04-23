include(FetchContent)

# SDL3 - Managing library within thirdparty/SDL3
# Latest Release: 3.4.4
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.4.4
)

set(SDL_SHARED ON CACHE BOOL "" FORCE)
set(SDL_STATIC OFF CACHE BOOL "" FORCE)
set(SDL_TEST OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(SDL3)
