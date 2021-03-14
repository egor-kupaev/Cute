cmake_minimum_required(VERSION 3.19)

project(Cute C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")

set(CMAKE_CXX_STANDARD 20)

# Dependencies
find_package(OpenGL REQUIRED)
include(cmake/fetch_glfw.cmake)
include(cmake/fetch_glm.cmake)
include(cmake/fetch_glew.cmake)
include(cmake/fetch_imgui.cmake)
include(cmake/fetch_stb_image.cmake)

# Cute
add_subdirectory(cute)

# Test
add_executable(Test main.cpp)
target_link_libraries(Test PRIVATE Cute)

add_custom_command(
        TARGET Test PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_LIST_DIR}/Resources
        ${CMAKE_CURRENT_BINARY_DIR}/Resources)
