# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.11)

# Set properties
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/../_DeepGameToolsBuild/bin )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/../_DeepGameToolsBuild/lib )
set ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/../_DeepGameToolsBuild/archive )

set ( CMAKE_CXX_STANDARD 17 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS OFF )

project ( "DeepGameTools" )

# Include sub-projects.
add_subdirectory ( "thirdparty" )
add_subdirectory ( "thirdparty/glm" )
add_subdirectory ( "DeepGameEngine" )
add_subdirectory ( "DeepPlatforms" )
add_subdirectory ( "DeepPlatforms/Linux" )
add_subdirectory ( "DeepPlatforms/MacOS" )
add_subdirectory ( "DeepPlatforms/Windows" )
add_subdirectory ( "DeepModules" )
add_subdirectory ( "DeepModules/DPWindow" )
