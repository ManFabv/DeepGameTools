# CMakeList.txt : game engine third party vulkan folder
#

include ( FetchContent )

FetchContent_Declare (
        vulkan
        GIT_REPOSITORY https://github.com/KhronosGroup/Vulkan-Headers.git
        GIT_TAG 4fee3efc189c83ccd26a9cd8265185c98458c94d #1.2.192
)

FetchContent_GetProperties ( vulkan )
if ( NOT vulkan_POPULATED )
    message ( STATUS "Fetching vulkan" )
    FetchContent_Populate ( vulkan )

    set ( SAMPLES_BUILD OFF CACHE INTERNAL "Build the vulkan samples" )

    add_subdirectory ( ${vulkan_SOURCE_DIR} ${vulkan_BINARY_DIR} )
endif ()
