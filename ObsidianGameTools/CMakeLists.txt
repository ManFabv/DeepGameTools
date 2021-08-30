# CMakeList.txt : CMake project for ObsidianGameTools, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (ObsidianGameTools "ObsidianGameTools.cpp" )

# Add tests and install targets if needed.
target_link_libraries ( ${CMAKE_PROJECT_NAME} PRIVATE glfw )