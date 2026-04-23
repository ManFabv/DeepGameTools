# CMakeList.txt : CMake project for Deep DPWindow subsystem, include source and define
# project specific logic here.
#

# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/DeepModules/DPWindow/include )

# Add library
add_library ( DPWindow 
              "include/DPWindow/DPWindow.h" "src/DPWindow.cpp"
)

# Link SDL3
target_link_libraries ( DPWindow PRIVATE SDL3::SDL3 )
