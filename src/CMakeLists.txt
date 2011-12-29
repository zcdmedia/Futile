# compiler flags
set (CMAKE_CXX_FLAGS "-g -lpng")

# source files list
set (SRC
	main.cpp
	color.cpp
	game.cpp futile.cpp
	gametime.cpp
	rawbuffer.cpp
)

# locate common libraries
find_package (OpenGL)

if (${Futile_LINUX})
	find_package (X11)
endif ()

# locate other libraries
find_library (Xxf86vm_LIBRARY Xxf86vm ${X11_LIB_SEARCH_PATH})
add_subdirectory (graphics)
add_subdirectory (math)
add_subdirectory (platform)
add_subdirectory (system)

# external library lis
set (LIB
	${OPENGL_LIBRARY}
	${X11_LIBRARY}
	${Xxf86vm_LIBRARY}
	graphics
	math
	platform
	system
)

# set the include path
include_directories (
	"${PROJECT_BINARY_DIR}/include"
	"${PROJECT_SOURCE_DIR}/include"
)

# add the executable
add_executable (futile ${SRC} pngio.c)

# link all libraries
target_link_libraries (futile ${LIB})

# install
install (TARGETS futile DESTINATION ${PROJECT_SOURCE_DIR}/bin)
