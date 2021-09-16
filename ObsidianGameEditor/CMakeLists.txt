# CMakeList.txt : CMake project for ObsidianGameEditor, include source and define
# project specific logic here.
#

# Include sub-projects.
add_subdirectory ( "thirdparty" )
add_subdirectory ( "thirdparty/wxwidgets" )

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/ObsidianGameEditor/include )

# Add source to this project's executable.
add_executable ( ObsidianGameEditor "include/OGameEditor/OGameEditorMainApp.h" "src/OGameEditorMainApp.cpp" #main entry point for editor
                                    "include/OGameEditor/OGameEditorMainFrame.h" "src/OGameEditorMainFrame.cpp"
)

# Add tests and install targets if needed.
target_link_libraries ( ObsidianGameEditor PRIVATE glm )
target_link_libraries ( ObsidianGameEditor PRIVATE wx::core wx::base )
