add_library(Cute STATIC
        # Engine
        source/engine/basic_engine.cpp

        # Graphics
        # Shapes
        source/graphics/shapes/box.cpp
        # Shaders
        source/graphics/shaders/shader.cpp
        # Vertices
        source/graphics/vertices/vertex_buffer.cpp
        source/graphics/vertices/vertex_array.cpp
        source/graphics/vertices/data_type.cpp

        # Testing
        source/testing/clear_scene.cpp
        source/testing/box_scene.cpp
        source/testing/camera_scene.cpp
        )
target_include_directories(Cute PUBLIC include)
target_compile_options(Cute PRIVATE /W4 /WX /std:c++latest)
target_link_libraries(Cute PUBLIC
        OpenGL::GL
        GLEW::GLEW
        glfw
        glm::glm
        StbImage
        ImGui_GLFW_OpenGL3
        )
target_compile_definitions(Cute PUBLIC GLEW_STATIC GLM_FORCE_SILENT_WARNINGS)
