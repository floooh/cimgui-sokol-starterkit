cmake_minimum_required(VERSION 3.0)
project(cimgui-sokol-starterkit)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

#=== LIBRARY: cimgui + Dear ImGui
add_library(cimgui STATIC 
    cimgui/cimgui.cpp 
    cimgui/cimgui.h 
    cimgui/imgui/imgui.cpp 
    cimgui/imgui/imgui_widgets.cpp 
    cimgui/imgui/imgui_draw.cpp 
    cimgui/imgui/imgui_demo.cpp)
target_include_directories(cimgui INTERFACE cimgui)

#=== LIBRARY: sokol
if(CMAKE_SYSTEM_NAME STREQUAL Darwin)
    add_library(sokol STATIC sokol/sokol.m)
    target_link_libraries(sokol
        "-framework QuartzCore"
        "-framework Cocoa"
        "-framework MetalKit"
        "-framework Metal")
else()
    add_library(sokol STATIC sokol/sokol.c)
    if (CMAKE_SYSTEM_NAME STREQUAL Linux)
        target_link_libraries(sokol X11 Xi Xcursor GL dl phtread m)
    endif()
endif()
target_link_libraries(sokol cimgui)
target_include_directories(sokol INTERFACE sokol)

if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    add_executable(demo WIN32 demo.c)
else()
    add_executable(demo demo.c)
endif()
target_link_libraries(demo sokol)

