# CMakeList.txt : CMake project for ObsidianGameEngine, include source and define
# project specific logic here.
#

# Include sub-projects.
add_subdirectory ( "thirdparty" )
add_subdirectory ( "thirdparty/vulkan" )
add_subdirectory ( "thirdparty/sdl" )

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/ObsidianGameEngine/include )

# Add source to this project's executable.
add_library ( ObsidianGameEngine 
                 "include/OGameEngine/OGameEngine.h"
                 "src/OGameEngine.cpp" 
)

# Add tests and install targets if needed.
target_link_libraries ( ObsidianGameEngine PRIVATE glm )
target_link_libraries ( ObsidianGameEngine PRIVATE Vulkan::Headers )
target_link_libraries ( ObsidianGameEngine PRIVATE SDL2::SDL2 SDL2::SDL2main )
