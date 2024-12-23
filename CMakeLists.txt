cmake_minimum_required(VERSION 3.10)
project(txt-editor)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(SFML_ROOT ${CMAKE_SOURCE_DIR}/ext/SFML-3.0.0)

# H:\Git\txt-editor\ext\SFML-3.0.0\include
set(SFML_INCLUDE_DIR ${SFML_ROOT}/include)
set(SFML_LIB_DIR ${SFML_ROOT}/lib)
set(SFML_DLL_DIR ${SFML_ROOT}/bin)

include_directories(${SFML_INCLUDE_DIR})

add_executable(txt-editor main.cpp)
target_link_libraries(txt-editor
    PUBLIC
    ${SFML_LIB_DIR}/sfml-graphics.lib
    ${SFML_LIB_DIR}/sfml-window.lib
    ${SFML_LIB_DIR}/sfml-system.lib
)
add_custom_command(TARGET txt-editor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${SFML_ROOT}/bin/sfml-system-3.dll $<TARGET_FILE_DIR:txt-editor>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${SFML_ROOT}/bin/sfml-window-3.dll $<TARGET_FILE_DIR:txt-editor>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${SFML_ROOT}/bin/sfml-graphics-3.dll $<TARGET_FILE_DIR:txt-editor>
)