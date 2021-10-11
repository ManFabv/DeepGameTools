# CMakeList.txt : CMake project for DeepGameEngine for Platform Linux, include source and define
# project specific logic here.
#

# Include sub-projects.

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/platforms/Linux/include )
include_directories ( ${PROJECT_SOURCE_DIR}/DeepGameEngine/include )

# Add source to this project's executable.
add_executable ( DeepGameEngineLinux "main.cpp" )

# Add tests and install targets if needed.
target_link_libraries ( DeepGameEngineLinux PRIVATE DeepGameEngine )
