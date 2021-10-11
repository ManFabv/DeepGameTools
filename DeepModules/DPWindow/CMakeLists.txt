# CMakeList.txt : CMake project for Deep DPWindow subsystem, include source and define
# project specific logic here.
#

# Include sub-projects.

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/DeepModules/DPWindow/include )

# Add source to this project's executable.
add_library ( DPWindow 
              "include/DPWindow/DPWindow.h" "src/DPWindow.cpp"
)

# Add tests and install targets if needed.
