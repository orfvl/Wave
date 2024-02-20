find_package(glfw3 CONFIG REQUIRED)
find_package(GLEW 2.2.0 REQUIRED)

add_library(shader shader/shader.h shader/shader.cpp)

set_target_properties(shader PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(shader PUBLIC GLEW::GLEW)

# set(OpenGL_GL_PREFERENCE GLVND)
# find_package(OpenGL 3.3 REQUIRED)
# target_link_libraries(shader PRIVATE OpenGL::OpenGL OpenGL::EGL)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/shader/shaders_src/shader.fs
${PROJECT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/shader/shaders_src/shader.vs
${PROJECT_BINARY_DIR} COPYONLY)

add_library(texture texture/texture.h texture/texture.cpp)

set_target_properties(texture PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(texture PUBLIC GLEW::GLEW)
target_include_directories(texture PUBLIC
                          "${PROJECT_SOURCE_DIR}/graphics/texture")

add_library(stb_image stb_image/stb_image.h stb_image/stb_image.cpp)

set_target_properties(stb_image PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(stb_image PUBLIC GLEW::GLEW)


add_library(resource_manager resource_manager/resource_manager.h resource_manager/resource_manager.cpp)
add_dependencies(resource_manager GLEW::GLEW  texture shader stb_image)
set_target_properties(resource_manager PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(resource_manager PRIVATE GLEW::GLEW)
target_link_libraries(resource_manager PUBLIC texture shader stb_image)
target_include_directories(resource_manager PUBLIC
                          "${PROJECT_SOURCE_DIR}/graphics/texture"
                          "${PROJECT_SOURCE_DIR}/graphics/shader"
                          "${PROJECT_SOURCE_DIR}/graphics/stb_image"
                          )

find_package(Freetype REQUIRED)

add_library(textRenderer textRenderer/textRenderer.h textRenderer/textRenderer.cpp)

set_target_properties(textRenderer PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(textRenderer PRIVATE GLEW::GLEW)
target_link_libraries(textRenderer PRIVATE Freetype::Freetype)
target_link_libraries(textRenderer PRIVATE texture shader resource_manager)
target_include_directories(textRenderer PUBLIC
                          "${PROJECT_SOURCE_DIR}/graphics/texture"
                          "${PROJECT_SOURCE_DIR}/graphics/shader"
                          "${PROJECT_SOURCE_DIR}/graphics/resource_manager"
                          )


add_library(graphics_manager graphics_manager/graphics_manager.hpp graphics_manager/graphics_manager.cpp)
set_target_properties(graphics_manager PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(graphics_manager PRIVATE GLEW::GLEW)
target_link_libraries(graphics_manager PRIVATE glfw)
target_link_libraries(graphics_manager PRIVATE texture shader resource_manager textRenderer)
target_include_directories(graphics_manager PUBLIC
                        "${PROJECT_BINARY_DIR}"
                        "${PROJECT_SOURCE_DIR}/graphics/texture"
                        "${PROJECT_SOURCE_DIR}/graphics/shader"
                        "${PROJECT_SOURCE_DIR}/graphics/resource_manager"
                        "${PROJECT_SOURCE_DIR}/graphics/textRenderer"
                        )

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textRenderer/text_shader/text_shader.fs
${PROJECT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/textRenderer/text_shader/text_shader.vs
${PROJECT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/fonts/a_ReportSansRgh.ttf
${PROJECT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/fonts/OCRAEXT.TTF
${PROJECT_BINARY_DIR} COPYONLY)

