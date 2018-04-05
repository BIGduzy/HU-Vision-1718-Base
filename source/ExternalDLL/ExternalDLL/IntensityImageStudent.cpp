#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other):
	IntensityImage(other.getWidth(), other.getHeight()),
	pixels(other.pixels)
{
	for (int i = 0; i<getWidth()*getHeight(); ++i) {
		pixels[i] = other.pixels[i];
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height):
	IntensityImage(width, height),
	pixels(width*height)
{}

IntensityImageStudent::~IntensityImageStudent() {}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	pixels.reserve(width * height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	set(other.getWidth(), other.getHeight());
	for (int i = 0; i < other.getWidth() * other.getHeight(); ++i) {
		pixels[i] = other.pixels[i];
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	setPixel(y * getWidth() + x, pixel);
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
	return getPixel(y * getWidth() + x);
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixels[i];
}