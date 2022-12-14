//
// libpixel
//
// (C) 2021-2022 modeco80 <lily.modeco80@protonmail.ch>
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//

#include <pixel/ImageWriter.h>
#include <pixel/RgbaImage.h>
#include "stb_image_write.h"

namespace pixel {

	void ImageWriter::SetImage(RgbaImage& image) {
		imagePtr = &image;
	}

	void ImageWriter::WritePng(const std::filesystem::path& outputPath) {
		// Make output paths if required.
		if(!std::filesystem::exists(outputPath.parent_path()))
			std::filesystem::create_directories(outputPath.parent_path());

		// TODO: Handle STB errors

		stbi_write_png(outputPath.string().c_str(), imagePtr->GetSize().width, imagePtr->GetSize().height, 4, imagePtr->GetBuffer(), static_cast<int>(imagePtr->GetStride()));
	}

} // namespace pixel
