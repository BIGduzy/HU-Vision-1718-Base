#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other):
	RGBImage(other.getWidth(), other.getHeight()),
	pixels(other.pixels)
{}


RGBImageStudent::RGBImageStudent(const int width, const int height): RGBImage(width, height) {
	pixels.resize(width * height);
}

RGBImageStudent::~RGBImageStudent() {
}

void RGBImageStudent::set(const int width, const int height) {
	if (pixels.size() != 0) {
		std::vector<RGB> tmpPixels(getWidth() * getHeight());
		const int scaleX = getWidth() / width;
		const int scaleY = getHeight() / height;

		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				tmpPixels[y * width + x] = pixels[y * scaleY * getWidth() + x * scaleX];
			}
		}
		pixels = tmpPixels;
	} else {
		pixels.resize(width * height);
	}
	RGBImage::set(width, height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	set(other.getWidth(), other.getHeight());
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pixels[y * getWidth() + x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
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

RGB RGBImageStudent::getPixel(int x, int y) const {
	return pixels[y * getWidth() + x];
}

RGB RGBImageStudent::getPixel(int i) const {
	return pixels[i];
}