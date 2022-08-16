//
// libpixel
//
// (C) 2021-2022 modeco80 <lily.modeco80@protonmail.ch>
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//

#include <pixel/RgbaColor.h>

namespace pixel {

	// could be made constexpr probably..

	RgbaColor RgbaColor::ColorFrom16Bpp(std::uint16_t color) {
		return {
			static_cast<std::uint8_t>((color & 0x001F) << 3),
			static_cast<std::uint8_t>((color & 0x03E0) >> 2),
			static_cast<std::uint8_t>((color & 0x7C00) >> 7),
			255
		};
	}

	void RgbaColor::PaletteFrom16Bpp(RgbaColor* dest, const std::uint8_t* src, std::size_t colorCount) {
		for(int i = 0; i < colorCount; ++i) {
			const auto colorIndex = i * sizeof(std::uint16_t);
			const std::uint16_t colorWord = (src[colorIndex + 1] << 8) | src[colorIndex];
			dest[i] = RgbaColor::ColorFrom16Bpp(colorWord);
		}
	}

} // namespace pixel