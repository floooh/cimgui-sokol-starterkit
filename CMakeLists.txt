cmake_minimum_required(VERSION 3.0)
project(cimgui-sokol-starterkit)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

#=== LIBRARY: cimgui + Dear ImGui
add_library(cimgui STATIC 
    cimgui/cimgui.cpp 
    cimgui/cimgui.h 
    cimgui/imgui/imgui.cpp
    cimgui/imgui/imgui.h
    cimgui/imgui/imgui_widgets.cpp 
    cimgui/imgui/imgui_draw.cpp 
    cimgui/imgui/imgui_demo.cpp)
target_include_directories(cimgui INTERFACE cimgui)

#=== LIBRARY: sokol
# add headers to the the file list because they are useful to have in IDEs
set(SOKOL_HEADERS
    sokol/sokol_gfx.h
    sokol/sokol_app.h
    sokol/sokol_time.h
    sokol/sokol_imgui.h
    sokol/sokol_glue.h)
if(CMAKE_SYSTEM_NAME STREQUAL Darwin)
    add_library(sokol STATIC sokol/sokol.m ${SOKOL_HEADERS})
    target_link_libraries(sokol
        "-framework QuartzCore"
        "-framework Cocoa"
        "-framework MetalKit"
        "-framework Metal")
else()
    add_library(sokol STATIC sokol/sokol.c ${SOKOL_HEADERS})
    if (CMAKE_SYSTEM_NAME STREQUAL Linux)
        target_link_libraries(sokol X11 Xi Xcursor GL dl pthread m)
    endif()
endif()
target_link_libraries(sokol cimgui)
target_include_directories(sokol INTERFACE sokol)

#=== EXECUTABLE: demo
if(CMAKE_SYSTEM_NAME STREQUAL Windows)
    add_executable(demo WIN32 demo.c)
else()
    add_executable(demo demo.c)
endif()
target_link_libraries(demo sokol)
# this hack removes the xxx-CMakeForceLinker.cxx dummy file
set_target_properties(demo PROPERTIES LINKER_LANGUAGE C)
