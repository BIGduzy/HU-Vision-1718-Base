#include "StudentPreProcessing.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent* intensityImage = new IntensityImageStudent(image.getWidth(), image.getHeight());

	for (int i = 0; i < image.getWidth() * image.getHeight(); ++i) {
		const auto& pixel = image.getPixel(i);

		// Avarage
		// intensityImage->setPixel(i, (pixel.r + pixel.g + pixel.b) / 3);

		// Max
		//intensityImage->setPixel(i, std::max({pixel.r, pixel.g, pixel.b}));
		
		// Min
		// intensityImage->setPixel(i, std::min({pixel.r, pixel.g, pixel.b}));

		// Luma (https://en.wikipedia.org/wiki/Grayscale)
		intensityImage->setPixel(i, (pixel.r * 0.299 + pixel.g * 0.587 + pixel.b * 0.114));
	}

	return intensityImage;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}