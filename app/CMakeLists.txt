cmake_minimum_required(VERSION 3.20)
add_library(app
	App.h
	App.cpp
)
set_target_properties(app PROPERTIES CXX_STANDARD 20)
target_link_libraries(app PRIVATE sokol)

include(GenerateExportHeader)
generate_export_header(app EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/Exports.h)