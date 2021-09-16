# CMakeList.txt : CMake project for ObsidianGameEngine for Platform MacOS, include source and define
# project specific logic here.
#

# Include sub-projects.
# add_subdirectory ( "thirdparty" )
# add_subdirectory ( "thirdparty/vulkan" )
# add_subdirectory ( "thirdparty/sdl" )

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/platforms/MacOS/include )
include_directories ( ${PROJECT_SOURCE_DIR}/ObsidianGameEngine/include )

# Add source to this project's executable.
add_executable ( ObsidianGameEngineMacOS "main.cpp" )

# Add tests and install targets if needed.
target_link_libraries ( ObsidianGameEngineMacOS PRIVATE ObsidianGameEngine )
