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
target_link_libraries(Wave PRIVATE glfw)
target_link_libraries(Wave PRIVATE GLEW::GLEW)
target_link_libraries(Wave PRIVATE OpenGL::OpenGL OpenGL::EGL)

add_subdirectory(graphics)
target_link_libraries(Wave PUBLIC shader)
target_link_libraries(Wave PUBLIC texture)
target_link_libraries(Wave PUBLIC resource_manager)
target_link_libraries(Wave PRIVATE textRenderer)
target_include_directories(Wave PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/graphics/texture"
                          "${PROJECT_SOURCE_DIR}/graphics/shader"
                          "${PROJECT_SOURCE_DIR}/graphics/resource_manager"
                          "${PROJECT_SOURCE_DIR}/graphics/textRenderer"
                          )
    