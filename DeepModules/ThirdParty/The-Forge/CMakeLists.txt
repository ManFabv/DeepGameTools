# CMakeList.txt : CMake project for The-Forge framework
#

cmake_minimum_required(VERSION 3.15)

project(The-Forge C CXX)

include(FetchContent)

# Automatically download and manage The-Forge via CMake
FetchContent_Declare(
    theforge_src
    GIT_REPOSITORY https://github.com/ConfettiFX/The-Forge.git
    GIT_TAG        master
    GIT_SHALLOW    TRUE
)

FetchContent_MakeAvailable(theforge_src)

set(THE_FORGE_DIR ${theforge_src_SOURCE_DIR})

# Define The-Forge interface library target
add_library(The-Forge INTERFACE)

target_include_directories(The-Forge INTERFACE
    $<BUILD_INTERFACE:${THE_FORGE_DIR}>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/OS>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/OS/Interfaces>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/Renderer>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/Renderer/Interfaces>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/Graphics>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/Graphics/Interfaces>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/Application>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/Application/Interfaces>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/Utilities>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/Utilities/Interfaces>
    $<BUILD_INTERFACE:${THE_FORGE_DIR}/Common_3/ThirdParty>
)
