# CMakeList.txt : CMake project for ObsidianGameEngine, include source and define
# project specific logic here.
#

# Include sub-projects.
add_subdirectory ( "thirdparty" )
add_subdirectory ( "thirdparty/vulkan" )

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/ObsidianGameEngine/include )

# Add source to this project's executable.
add_executable ( ObsidianGameEngine "main.cpp" )

# Add tests and install targets if needed.
target_link_libraries ( ObsidianGameEngine PRIVATE glm )
target_link_libraries ( ObsidianGameEngine PRIVATE Vulkan::Headers )
