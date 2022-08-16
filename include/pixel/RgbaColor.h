//
// libpixel
//
// (C) 2021-2022 modeco80 <lily.modeco80@protonmail.ch>
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//

#ifndef LIBPIXEL_RGBACOLOR_H
#define LIBPIXEL_RGBACOLOR_H

#include <cstdint>

namespace pixel {

	/**
	 * A RGBA8888 color.
	 */
	union RgbaColor {
	   private:
		/**
		 * Data representation.
		 */
		std::uint32_t u32 {};

	   public:
		// maybe provide ctors?

		constexpr RgbaColor() = default;

		constexpr RgbaColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
			: r(r),
			  g(g),
			  b(b),
			  a(a) {
		}

		struct {
			std::uint8_t r;
			std::uint8_t g;
			std::uint8_t b;
			std::uint8_t a;
		};

		[[nodiscard]] constexpr std::uint32_t GetRep() const {
			return u32;
		}

		// TODO: Maybe:
		//
		static RgbaColor ColorFrom16Bpp(std::uint16_t);
		static void PaletteFrom16Bpp(RgbaColor* dest, const std::uint8_t* src, std::size_t colorCount);
	};
} // namespace pixel

#endif // LIBPIXEL_RGBACOLOR_H
