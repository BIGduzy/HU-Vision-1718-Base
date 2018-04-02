#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other):
	IntensityImage(other.getWidth(), other.getHeight()),
	pixels(other.pixels)
{}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixels.resize(width * height);
}

IntensityImageStudent::~IntensityImageStudent() {}

void IntensityImageStudent::set(const int width, const int height) {
	if (pixels.size() != 0) {
		std::vector<Intensity> tmpPixels(getWidth() * getHeight());
		const int scaleX = getWidth() / width;
		const int scaleY = getHeight() / height;

		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				tmpPixels[y * width + x] = pixels[y * scaleY * getWidth() + x * scaleX];
				tmpPixels[y * width + x] = 3;
			}
		}
		pixels = tmpPixels;
	} else {
		pixels.resize(width * height);
	}
	IntensityImage::set(width, height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	set(other.getWidth(), other.getHeight());
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixels[y * getWidth() + x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	/*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
	pixels[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixels[y * getWidth() + x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixels[i];
}