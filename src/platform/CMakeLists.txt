# compiler flags
set (CMAKE_CXX_FLAGS "-g")

# platform libraries
if (Futile_APPLE)
	set (platform_lib apple)
elseif (Futile_LINUX)
	set (platform_lib linux)
elseif (Futile_WIN32)
	set (platform_lib win32)
endif ()

# add the platform's subdirectory
add_subdirectory (${platform_lib})

# source files list
set (PLATFORM_SRC windowfactory.cpp)

# set the include path
include_directories (
	"${PROJECT_BINARY_DIR}/include"
	"${PROJECT_SOURCE_DIR}/include"
)

# add the executable
add_library (platform SHARED ${PLATFORM_SRC})

# link platform library
target_link_libraries (platform platform_${platform_lib})
