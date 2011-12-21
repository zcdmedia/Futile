# compiler flags
set (CMAKE_CXX_FLAGS "-g")

# source files list
set (PLATFORM_SRC
	windowfactory.cpp
	xwindow.cpp xfullscreenwindow.cpp xwindowedwindow.cpp
)

# set the include path
include_directories (
	"${PROJECT_BINARY_DIR}/include"
	"${PROJECT_SOURCE_DIR}/include"
)

# add the executable
add_library (platform SHARED ${PLATFORM_SRC})
