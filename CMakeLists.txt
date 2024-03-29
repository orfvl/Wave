cmake_minimum_required(VERSION 3.10)

project(Wave)

set(CMAKE_CXX_CLANG_TIDY)
set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE Debug)

find_package(fmt CONFIG REQUIRED)

find_package(glfw3 CONFIG REQUIRED)

find_package(GLEW 2.2.0 REQUIRED)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL 3.3 REQUIRED)


add_executable(Wave wave.cpp)

target_link_libraries(Wave PRIVATE fmt::fmt)
target_link_libraries(Wave PRIVATE OpenGL::OpenGL OpenGL::EGL)

add_subdirectory(graphics)
target_link_libraries(Wave PRIVATE graphics_manager)
target_include_directories(Wave PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/graphics/graphics_manager"
                          )
    