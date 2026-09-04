# CMakeList.txt : CMake project for DeepGameEngine, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library ( DeepGameEngine 
              "include/DPGameEngine/DPGameEngine.h"
              "src/DPGameEngine.cpp" 
)

# Include sub-projects.

# Add include directories
target_include_directories(DeepGameEngine
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Add tests and install targets if needed.
target_link_libraries ( DeepGameEngine PUBLIC DPWindow )
