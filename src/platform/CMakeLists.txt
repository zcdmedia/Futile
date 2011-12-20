# compiler flags
set (CMAKE_CXX_FLAGS "-g")

# source files list
set (PLATFORM_SRC xwindow.cpp xfullscreenwindow.cpp)

# set the include path
include_directories (
	"${PROJECT_BINARY_DIR}/include"
	"${PROJECT_SOURCE_DIR}/include"
)

# add the executable
add_library (platform ${PLATFORM_SRC})
