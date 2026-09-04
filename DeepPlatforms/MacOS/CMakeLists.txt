# CMakeList.txt : CMake project for DeepGameEngine for Platform MacOS, include source and define
# project specific logic here.
#

# Include sub-projects.

# Add include directories

# Add source to this project's executable.
add_executable ( DeepGameEngineMacOS "../main.cpp" )

# Add tests and install targets if needed.
target_link_libraries ( DeepGameEngineMacOS PRIVATE DeepGameEngine DPWindow SDL3::SDL3 )