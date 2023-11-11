cmake_minimum_required(VERSION 3.26)
project(opengl)
find_package( OpenGL REQUIRED )


set( GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE )
set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE )

# Build vendor code
add_subdirectory("vendor/glfw")
add_subdirectory("vendor/glew")



set(source_files 
    src/main.cpp
    src/math3d.hpp
    src/renderer.hpp
    src/triangle.hpp
)

add_executable(opengl ${source_files}) 

target_include_directories( opengl
                            PRIVATE vendor/glew/include
                            PRIVATE vendor/glfw/include
)
target_link_libraries(opengl 
                        glfw
                        ${GLFW_LIBRARIES}
                        libglew_static
                        Opengl32
                    )
target_compile_options(opengl PRIVATE -Wall -Wextra)
