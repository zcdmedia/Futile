# compiler flags
set (CMAKE_CXX_FLAGS "-g")

# source files list
set (PLATFORM_LINUX_SRC
	window.cpp
	fullscreenwindow.cpp
	windowedwindow.cpp
)

# set the include path
include_directories (
	"${PROJECT_BINARY_DIR}/include"
	"${PROJECT_SOURCE_DIR}/include"
)

# add the executable
add_library (platform_linux SHARED ${PLATFORM_LINUX_SRC})
