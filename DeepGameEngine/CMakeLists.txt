# CMakeList.txt : CMake project for DeepGameEngine, include source and define
# project specific logic here.
#

# Include sub-projects.


# Add include directories
include_directories ( ${PROJECT_SOURCE_DIR}/DeepGameEngine/include )
include_directories ( ${PROJECT_SOURCE_DIR}/DeepModules/DPWindow/include )

# Add source to this project's executable.
add_library ( DeepGameEngine 
              "include/DPGameEngine/DPGameEngine.h"
              "src/DPGameEngine.cpp" 
)

# Add tests and install targets if needed.
target_link_libraries ( DeepGameEngine PRIVATE glm )
target_link_libraries ( DeepGameEngine PRIVATE DPWindow )
