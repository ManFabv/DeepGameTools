# CMakeList.txt : CMake project for ObsidianGameEngine for Platform Linux, include source and define
# project specific logic here.
#

# Include sub-projects.

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/platforms/Linux/include )
include_directories ( ${PROJECT_SOURCE_DIR}/ObsidianGameEngine/include )

# Add source to this project's executable.
add_executable ( ObsidianGameEngineLinux "main.cpp" )

# Add tests and install targets if needed.
target_link_libraries ( ObsidianGameEngineLinux PRIVATE ObsidianGameEngine )
