# compiler flags
set (CMAKE_CXX_FLAGS "-g")

# source files list
set (MATH_SRC
	tuple2.cpp tuple3.cpp tuple4.cpp
	matrix3.cpp matrix4.cpp
	point2.cpp point3.cpp point4.cpp
	quad.cpp
	rectangle.cpp
	transform.cpp
	vector2.cpp vector3.cpp vector4.cpp
)

# set the include path
include_directories (
	"${PROJECT_BINARY_DIR}/include"
	"${PROJECT_SOURCE_DIR}/include"
)

# add the executable
add_library (math SHARED ${MATH_SRC})
