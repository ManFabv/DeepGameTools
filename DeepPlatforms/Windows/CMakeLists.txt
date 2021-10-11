# CMakeList.txt : CMake project for DeepGameEngine for Platform Windows, include source and define
# project specific logic here.
#

# Include sub-projects.
# add_subdirectory ( "thirdparty" )
# add_subdirectory ( "thirdparty/vulkan" )
# add_subdirectory ( "thirdparty/sdl" )

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/platforms/Windows/include )
include_directories ( ${PROJECT_SOURCE_DIR}/DeepGameEngine/include )

# Add source to this project's executable.
add_executable ( DeepGameEngineWindows "main.cpp" )

# Add tests and install targets if needed.
target_link_libraries ( DeepGameEngineWindows PRIVATE DeepGameEngine )
