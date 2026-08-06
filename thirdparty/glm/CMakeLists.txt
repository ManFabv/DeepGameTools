# CMakeList.txt : common third party glm folder
#

include ( FetchContent )

FetchContent_Declare (
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 8d1fd52e5ab5590e2c81768ace50c72bae28f2ed #1.0.3
)

message ( STATUS "Fetching glm" )
FetchContent_MakeAvailable ( glm )
