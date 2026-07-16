cmake_minimum_required(VERSION 3.20)

project(LikeDreamerRe LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT MSVC)
    message(FATAL_ERROR "LikeDreamerRe currently targets Windows/MSVC because this scaffold links the official DxLib VC package.")
endif()

set(DXLIB_ROOT "E:/fork/DxLibVCTest/DxLibVCTest" CACHE PATH "Directory containing DxLib.h and DxLib *_vs2015_x64_MD.lib files")
get_filename_component(DXLIB_ROOT "${DXLIB_ROOT}" ABSOLUTE)

if(NOT EXISTS "${DXLIB_ROOT}/DxLib.h")
    message(FATAL_ERROR "DXLIB_ROOT does not contain DxLib.h: ${DXLIB_ROOT}")
endif()

set(DXLIB_LIBS
    DxDrawFunc_vs2015_x64_MD.lib
    DxLib_vs2015_x64_MD.lib
    DxUseCLib_vs2015_x64_MD.lib
    celt_vs2015_x64_MD.lib
    libbulletcollision_vs2015_x64_MD.lib
    libbulletdynamics_vs2015_x64_MD.lib
    libbulletmath_vs2015_x64_MD.lib
    libjpeg_vs2015_x64_MD.lib
    libpng_vs2015_x64_MD.lib
    libtheora_static_vs2015_x64_MD.lib
    libtiff_vs2015_x64_MD.lib
    ogg_static_vs2015_x64_MD.lib
    opus_vs2015_x64_MD.lib
    opusfile_vs2015_x64_MD.lib
    silk_common_vs2015_x64_MD.lib
    vorbis_static_vs2015_x64_MD.lib
    vorbisfile_static_vs2015_x64_MD.lib
    zlib_vs2015_x64_MD.lib
)

foreach(DXLIB_LIB_NAME IN LISTS DXLIB_LIBS)
    if(NOT EXISTS "${DXLIB_ROOT}/${DXLIB_LIB_NAME}")
        message(FATAL_ERROR "Required DxLib library is missing: ${DXLIB_ROOT}/${DXLIB_LIB_NAME}")
    endif()
endforeach()

add_executable(LikeDreamerRe WIN32
    src/app.cpp
    src/frontend_runtime.cpp
    src/main.cpp
    src/path_utils.cpp
    src/resource_manager.cpp
    src/resource_tables.cpp
    src/save_config.cpp
    src/stage_probe.cpp
    src/stage_runtime.cpp
    src/stage_runtime_pause.cpp
    src/stage_runtime_boss07.cpp
    src/stage_runtime_boss08.cpp
    src/stage_runtime_boss09.cpp
    src/stage_runtime_boss10_aux.cpp
    src/stage_runtime_scene10.cpp
    src/stage_runtime_enemy06.cpp
    src/stage_runtime_enemy07.cpp
    src/stage_runtime_enemy08.cpp
    src/stage_runtime_enemy10.cpp
    src/stage_runtime_late.cpp
    src/stage_runtime_midboss06.cpp
    src/stage_runtime_midboss07.cpp
    src/stage_runtime_midboss09.cpp
    src/stage_runtime_midboss09_tail.cpp
    src/stage_runtime_stage05_07.cpp
    src/stage_runtime_stage08_10.cpp
    src/steam_stub.cpp
    src/text_database.cpp
)

target_include_directories(LikeDreamerRe PRIVATE
    "${DXLIB_ROOT}"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/../headers"
)

target_link_directories(LikeDreamerRe PRIVATE "${DXLIB_ROOT}")

target_compile_definitions(LikeDreamerRe PRIVATE
    NOMINMAX
    WIN32_LEAN_AND_MEAN
    _CRT_SECURE_NO_WARNINGS
)

target_compile_options(LikeDreamerRe PRIVATE /W4 /permissive-)

target_link_libraries(LikeDreamerRe PRIVATE
    ${DXLIB_LIBS}
    winmm
    imm32
    version
    setupapi
    dinput8
    dxguid
    d3d11
    d3d9
    dwrite
    windowscodecs
    ole32
    oleaut32
    uuid
    gdi32
    user32
    advapi32
    shell32
)

set_property(TARGET LikeDreamerRe PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

message(STATUS "DxLib root: ${DXLIB_ROOT}")
message(STATUS "DxLib libraries: ${DXLIB_LIBS}")
