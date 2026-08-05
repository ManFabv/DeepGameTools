# CMakeList.txt : CMake project for SDL3 dependency
#

cmake_minimum_required(VERSION 3.15)

project(SDL3 C CXX)

include(FetchContent)

# Automatically download and manage SDL3 via CMake
FetchContent_Declare(
    sdl3_src
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG        release-3.4.x
    GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(sdl3_src)

set(SDL3_DIR ${sdl3_src_SOURCE_DIR})

# Define SDL3 interface library target
add_library(SDL3 INTERFACE)

target_include_directories(SDL3 INTERFACE
    $<BUILD_INTERFACE:${SDL3_DIR}/include>
)

target_link_libraries(SDL3 INTERFACE
    SDL3::SDL3
)
