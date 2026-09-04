# CMakeList.txt : platforms folder where all the exports will be available
#

# Include sub-projects.
if(APPLE)
    add_subdirectory(MacOS)
elseif(WIN32)
    add_subdirectory(Windows)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_subdirectory(Linux)
endif()
