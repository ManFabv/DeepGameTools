# CMakeList.txt : common third party glm folder
#

include ( FetchContent )

FetchContent_Declare (
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG bf71a834948186f4097caa076cd2663c69a10e1e #0.9.9.8
)

FetchContent_GetProperties ( glm )
if ( NOT glm_POPULATED )
    message ( STATUS "Fetching glm" )
    FetchContent_Populate ( glm )

    add_subdirectory ( ${glm_SOURCE_DIR} ${glm_BINARY_DIR} )
endif ()
