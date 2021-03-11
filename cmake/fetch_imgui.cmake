include(FetchContent)
FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.81
)
FetchContent_GetProperties(imgui)
if (NOT imgui_POPULATED)
    FetchContent_Populate(imgui)

    # Copy ImGui sources to ImGui/source/
    file(GLOB sources ${imgui_SOURCE_DIR}/*.cpp)
    FILE(COPY ${sources} DESTINATION ${imgui_SOURCE_DIR}/ImGui/source/)

    # Copy ImGui headers to ImGui/include/
    file(GLOB headers ${imgui_SOURCE_DIR}/*.h)
    FILE(COPY ${headers} DESTINATION ${imgui_SOURCE_DIR}/ImGui/include/)

    # Copy ImGui backends sources to ImGui/Backends/source/
    file(GLOB sources ${imgui_SOURCE_DIR}/backends/*.cpp)
    FILE(COPY ${sources} DESTINATION ${imgui_SOURCE_DIR}/ImGui/Backends/source/)

    # Copy ImGui backends headers to ImGui/Backends/include/
    file(GLOB headers ${imgui_SOURCE_DIR}/backends/*.h)
    FILE(COPY ${headers} DESTINATION ${imgui_SOURCE_DIR}/ImGui/Backends/include/)
endif ()

message(STATUS ${imgui_SOURCE_DIR})

add_library(ImGui STATIC
        ${imgui_SOURCE_DIR}/ImGui/source/imgui.cpp
        ${imgui_SOURCE_DIR}/ImGui/source/imgui_demo.cpp
        ${imgui_SOURCE_DIR}/ImGui/source/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/ImGui/source/imgui_tables.cpp
        ${imgui_SOURCE_DIR}/ImGui/source/imgui_widgets.cpp
        )
target_include_directories(ImGui PUBLIC ${imgui_SOURCE_DIR}/ImGui/include)

add_library(ImGui_GLFW_OpenGL3 STATIC
        ${imgui_SOURCE_DIR}/ImGui/Backends/source/imgui_impl_glfw.cpp
        ${imgui_SOURCE_DIR}/ImGui/Backends/source/imgui_impl_opengl3.cpp
        )
target_include_directories(ImGui_GLFW_OpenGL3 PUBLIC ${imgui_SOURCE_DIR}/ImGui/Backends/include)
target_link_libraries(ImGui_GLFW_OpenGL3 PUBLIC
        ImGui
        OpenGL::GL
        GLEW::GLEW
        glfw
        )
target_compile_definitions(ImGui_GLFW_OpenGL3 PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLEW)
