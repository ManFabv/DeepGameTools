# CMakeList.txt : CMake project for DeepGameEngine for Platform MacOS, include source and define
# project specific logic here.
#

# Include sub-projects.
add_subdirectory ( "Frameworks" )

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/platforms/MacOS/include )
include_directories ( ${PROJECT_SOURCE_DIR}/DeepGameEngine/include )

# Add source to this project's executable.
add_executable ( DeepGameEngineMacOS "main.cpp" )

# Add tests and install targets if needed.
target_link_libraries ( DeepGameEngineMacOS PRIVATE DeepGameEngine )
