include(FetchContent)
FetchContent_Declare(
        glew
        URL https://github.com/nigels-com/glew/releases/download/glew-2.2.0/glew-2.2.0-win32.zip
)
FetchContent_GetProperties(glew)
if (NOT glew_POPULATED)
    FetchContent_Populate(glew)
endif ()

set(GLEW_LOCATION ${glew_SOURCE_DIR})
find_package(OwnGLEW REQUIRED)
