cmake_minimum_required (VERSION 2.8)
project (Futile)

# version
set (Futile_VERSION_MAJOR 0)
set (Futile_VERSION_MINOR 0)

# source
add_subdirectory(src)

# set build environment information
# check for apple (doesn't necessarily mean Mac OS X)
if (${APPLE})
	set (Futile_APPLE 1)
else ()
	set (Futile_APPLE 0)
endif ()

# check for linux
if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
	set (Futile_LINUX 1)
else ()
	set (Futile_LINUX 0)
endif ()

# check for windows
if (${WIN32})
	set (Futile_WIN32 1)
else ()
	set (Futile_WIN32 0)
endif ()

# config header file
configure_file (
	"${PROJECT_SOURCE_DIR}/include/futile/config.h.in"
	"${PROJECT_BINARY_DIR}/include/futile/config.h"
)
