//
// libpixel
//
// (C) 2021-2022 modeco80 <lily.modeco80@protonmail.ch>
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//

#include <pixel/RgbaImage.h>

namespace pixel {

	RgbaImage::RgbaImage() = default;

	RgbaImage::RgbaImage(ImageSize size) {
		Resize(size);
	}

	// This is probably trivial.
	RgbaImage::RgbaImage(RgbaImage&& movee) noexcept {
		pixels = std::move(movee.pixels);
		size = std::move(movee.size);
	}

	void RgbaImage::Resize(ImageSize sz) {
		// Clear any remaining image.
		if(pixels)
			Clear();

		// if only i could use make_shared...
		pixels.reset(new RgbaColor[sz.width * sz.height]);
		size = sz;
	}

	void RgbaImage::Clear() {
		if(!pixels) {
			pixels.reset();
			size = { 0, 0 };
		}
	}

	const RgbaColor* RgbaImage::GetBuffer() const {
		return pixels.get();
	}

	RgbaColor* RgbaImage::GetBuffer() {
		return pixels.get();
	}

	std::size_t RgbaImage::GetStride() const {
		return 4 * size.width;
	}

	ImageSize RgbaImage::GetSize() const {
		return size;
	}

	RgbaImage RgbaImage::From4Bpp(const std::uint8_t* data, const RgbaColor* palette, ImageSize size) {
		RgbaImage image(size);
		auto* buffer = image.GetBuffer();

		for(std::size_t i = 0; i < (size.width * size.height / 2); ++i)
			for(std::size_t b = 0; b < 2; b++)
				*(buffer++) = palette[static_cast<std::uint16_t>(((data[i] & (0x0F << (b * 4))) >> (b * 4)))];

		return image;
	}

	RgbaImage RgbaImage::From8Bpp(const std::uint8_t* data, const RgbaColor* palette, ImageSize size) {
		RgbaImage image(size);
		auto* buffer = image.GetBuffer();

		for(std::size_t i = 0; i < size.width * size.height; ++i)
			*(buffer++) = palette[data[i]];

		return image;
	}

} // namespace pixel