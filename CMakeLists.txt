cmake_minimum_required (VERSION 2.8)
project (Futile)

# version
set (Futile_VERSION_MAJOR 0)
set (Futile_VERSION_MINOR 0)

# source
add_subdirectory(src)

# config header file
configure_file (
	"${PROJECT_SOURCE_DIR}/include/config.h.in"
	"${PROJECT_BINARY_DIR}/include/config.h"
)
