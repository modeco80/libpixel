add_library(pixel_libpixel
		stb_impl.cpp

		RgbaColor.cpp
		RgbaImage.cpp
		ImageWriter.cpp
		)

target_include_directories(pixel_libpixel PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(pixel_libpixel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# we only use stb internally
target_link_libraries(pixel_libpixel PRIVATE
	stb::stb
	)

set_target_properties(pixel_libpixel PROPERTIES
		CXX_STANDARD 20
		CXX_STANDARD_REQUIRED ON
		)

# Please use this alias.
add_library(pixel::libpixel ALIAS pixel_libpixel)
