include(FetchContent)
FetchContent_Declare(
        stb
        GIT_REPOSITORY https://github.com/nothings/stb.git
        GIT_TAG master
)
FetchContent_GetProperties(stb)
if (NOT stb_POPULATED)
    FetchContent_Populate(stb)
    file(COPY ${stb_SOURCE_DIR}/stb_image.h DESTINATION ${stb_SOURCE_DIR}/StbImage/include/)
    file(COPY ${stb_SOURCE_DIR}/stb_image.h DESTINATION ${stb_SOURCE_DIR}/StbImage/source/)
    file(RENAME ${stb_SOURCE_DIR}/StbImage/source/stb_image.h ${stb_SOURCE_DIR}/StbImage/source/stb_image.c)
endif ()


add_library(StbImage STATIC
        ${stb_SOURCE_DIR}/StbImage/source/stb_image.c
        )
target_include_directories(StbImage PUBLIC ${stb_SOURCE_DIR}/StbImage/include/)
target_compile_definitions(StbImage PRIVATE STB_IMAGE_IMPLEMENTATION)
