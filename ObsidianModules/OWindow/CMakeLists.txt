# CMakeList.txt : CMake project for Obsidian OWindow subsystem, include source and define
# project specific logic here.
#

# Include sub-projects.

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/ObsidianModules/OWindow/include )

# Add source to this project's executable.
add_library ( OWindow 
              "include/OWindow/OWindow.h" "src/OWindow.cpp"
)

# Add tests and install targets if needed.
