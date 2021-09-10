# CMakeList.txt : CMake project for ObsidianGameEditor, include source and define
# project specific logic here.
#

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/${CMAKE_PROJECT_NAME}/include )

# Add source to this project's executable.
add_executable ( ${CMAKE_PROJECT_NAME} "include/ObsidianGameEditorMainApp.h" "src/ObsidianGameEditorMainApp.cpp" #main entry point for editor
                                       "include/ObsidianGameEditorMainFrame.h" "src/ObsidianGameEditorMainFrame.cpp"
                                      )

# Include sub-projects.
add_subdirectory ( "thirdparty" )
add_subdirectory ( "thirdparty/wxwidgets" )

# Add tests and install targets if needed.
target_link_libraries ( ${CMAKE_PROJECT_NAME} PRIVATE glm )
target_link_libraries ( ${CMAKE_PROJECT_NAME} PRIVATE wx::core wx::base )
