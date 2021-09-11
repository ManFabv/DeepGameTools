# CMakeList.txt : CMake project for ObsidianGameEditor, include source and define
# project specific logic here.
#

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/ObsidianGameEditor/include )

# Add source to this project's executable.
add_executable ( ObsidianGameEditor "include/ObsidianGameEditorMainApp.h" "src/ObsidianGameEditorMainApp.cpp" #main entry point for editor
                                       "include/ObsidianGameEditorMainFrame.h" "src/ObsidianGameEditorMainFrame.cpp"
                                      )

# Include sub-projects.
add_subdirectory ( "thirdparty" )
add_subdirectory ( "thirdparty/wxwidgets" )

# Add tests and install targets if needed.
target_link_libraries ( ObsidianGameEditor PRIVATE glm )
target_link_libraries ( ObsidianGameEditor PRIVATE wx::core wx::base )
