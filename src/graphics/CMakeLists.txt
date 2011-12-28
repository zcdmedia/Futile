# compiler flags
set (CMAKE_CXX_FLAGS "-g")

# source files list
set (SRC
	graphicscontext.cpp
	spritebatch.cpp
	texture.cpp texture2d.cpp
)

# set the include path
include_directories (
	"${PROJECT_BINARY_DIR}/include"
	"${PROJECT_SOURCE_DIR}/include"
)

# add the executable
add_library (graphics SHARED ${SRC})
