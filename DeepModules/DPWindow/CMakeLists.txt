# CMakeList.txt : CMake project for Deep DPWindow subsystem, include source and define
# project specific logic here.
#

# Include sub-projects.

# Add source to this project's executable.
add_library ( DPWindow 
              "include/DPWindow/DPWindow.h" "src/DPWindow.cpp"
)

# Add include directories
target_include_directories(DPWindow
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Add tests and install targets if needed.
