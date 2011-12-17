# source files list
set (SRC main.cpp dimension2d.cpp window.cpp xwindow.cpp)

# locate common libraries
find_package (OpenGL)
find_package (X11)

# locate other libraries
find_library (Xxf86vm_LIBRARY Xxf86vm ${X11_LIB_SEARCH_PATH})

# library list
set (LIB ${OPENGL_LIBRARY} ${X11_LIBRARY} ${Xxf86vm_LIBRARY})

# set the include path
include_directories ("${PROJECT_BINARY_DIR}/include")

# add the executable
add_executable (futile ${SRC})

# link all libraries
target_link_libraries (futile ${LIB})

# install
install (TARGETS futile DESTINATION ${PROJECT_SOURCE_DIR}/bin)
