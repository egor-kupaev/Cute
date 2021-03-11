include(FindPackageHandleStandardArgs)

find_path(GLEW_INCLUDE_DIR
    NAMES
        GL/glew.h
    PATHS
        ${GLEW_LOCATION}/include
    )

# TODO: Add linux support
if (ARCH MATCHES "x86")
    find_library(GLEW_LIBRARY
        NAMES
            glew32s
        PATHS
            ${GLEW_LOCATION}/lib/Release/Win32/)
else()
    find_library(GLEW_LIBRARY
        NAMES
            glew32s
        PATHS
            ${GLEW_LOCATION}/lib/Release/x64/)
endif()

find_package_handle_standard_args(OwnGLEW DEFAULT_MSG
    GLEW_INCLUDE_DIR
    GLEW_LIBRARY
    )

add_library(GLEW::GLEW STATIC IMPORTED)
set_target_properties(GLEW::GLEW PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES ${GLEW_INCLUDE_DIR}
    IMPORTED_LOCATION             ${GLEW_LIBRARY})
