add_library(stb_stb INTERFACE)
target_include_directories(stb_stb INTERFACE ${CMAKE_CURRENT_LIST_DIR}/stb)

add_library(stb::stb ALIAS stb_stb)
