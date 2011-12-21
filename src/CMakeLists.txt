# compiler flags
set (CMAKE_CXX_FLAGS "-g")

# source files list
set (SRC main.cpp)

# locate common libraries
find_package (OpenGL)
find_package (X11)

# locate other libraries
find_library (Xxf86vm_LIBRARY Xxf86vm ${X11_LIB_SEARCH_PATH})
add_subdirectory (math)
add_subdirectory (platform)

# external library lis
set (LIB
	${OPENGL_LIBRARY}
	${X11_LIBRARY}
	${Xxf86vm_LIBRARY}
	math
	platform
)

# set the include path
include_directories (
	"${PROJECT_BINARY_DIR}/include"
	"${PROJECT_SOURCE_DIR}/include"
)

# add the executable
add_executable (futile ${SRC})

# link all libraries
target_link_libraries (futile ${LIB})

# install
install (TARGETS futile DESTINATION ${PROJECT_SOURCE_DIR}/bin)
