add_library(Cute STATIC
        # Engine
        source/Engine/BasicEngine.cpp

        # Graphics
            # Shapes
            source/Graphics/Shapes/Box.cpp
            # Shaders
            source/Graphics/Shaders/Shader.cpp
            # Vertices
            source/Graphics/Vertices/VertexBuffer.cpp
            source/Graphics/Vertices/VertexArray.cpp
            source/Graphics/Vertices/DataType.cpp

        # Testing
        source/Testing/ClearScene.cpp
        source/Testing/BoxScene.cpp
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
