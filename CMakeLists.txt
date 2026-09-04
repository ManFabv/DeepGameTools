# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required(VERSION 3.25...4.0)

project ( "DeepGameTools" VERSION 0.1.0 LANGUAGES CXX )

set ( CMAKE_CXX_STANDARD 17 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS OFF )

# Set properties
set ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
set ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/archive )

# Include sub-projects.
add_subdirectory(ThirdParty)
add_subdirectory(DeepModules)
add_subdirectory(DeepGameEngine)
add_subdirectory(DeepPlatforms)