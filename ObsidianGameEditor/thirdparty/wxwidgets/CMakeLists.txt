# CMakeList.txt : game editor third party wxwidgets folder
#

include ( FetchContent )

FetchContent_Declare(
        wxwidgets
        GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
        GIT_TAG 9c0a8be1dc32063d91ed1901fd5fcd54f4f955a1 #3.1.5
)

FetchContent_GetProperties ( wxwidgets )
if ( NOT wxwidgets_POPULATED )
    message( STATUS "Fetching wxwidgets" )
    FetchContent_Populate ( wxwidgets )

    set ( wxBUILD_TESTS OFF CACHE INTERNAL "Run the wxwidgets tests" )
    set ( wxBUILD_SAMPLES OFF CACHE INTERNAL "Build the wxwidgets samples" )
    set ( wxBUILD_DEMOS OFF CACHE INTERNAL "Build the wxwidgets demos" )
    set ( wxBUILD_PRECOMP OFF CACHE INTERNAL "Generate wxwidgets precompiled headers target" )

    add_subdirectory ( ${wxwidgets_SOURCE_DIR} ${wxwidgets_BINARY_DIR} )
endif ()
