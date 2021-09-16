# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.11)

# Set properties
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/../_ObsidianGameToolsBuild/bin )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/../_ObsidianGameToolsBuild/lib )
set ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/../_ObsidianGameToolsBuild/archive )

set ( CMAKE_CXX_STANDARD 17 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )

project ( "ObsidianGameTools" )

# Include sub-projects.
add_subdirectory ( "thirdparty" )
add_subdirectory ( "thirdparty/glm" )
add_subdirectory ( "ObsidianGameEngine" )
add_subdirectory ( "ObsidianGameEditor" )
add_subdirectory ( "ObsidianGameEnginePlatforms" )
add_subdirectory ( "ObsidianGameEnginePlatforms/MacOS" )
