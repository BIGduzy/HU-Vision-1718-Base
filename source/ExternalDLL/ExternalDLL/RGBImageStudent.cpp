#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other):
	RGBImage(other.getWidth(), other.getHeight()),
	pixels(other.pixels)
{
	for (int i = 0; i<getWidth()*getHeight(); ++i) {
		pixels[i] = other.pixels[i];
	}
}


RGBImageStudent::RGBImageStudent(const int width, const int height): RGBImage(width, height),
pixels(width*height){
}

RGBImageStudent::~RGBImageStudent() {
}

void RGBImageStudent::set(const int width, const int height) {
	RGBImage::set(width, height);
	pixels.resize(width * height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	set(other.getWidth(), other.getHeight());
	for (int i = 0; i < other.getWidth() * other.getHeight(); ++i) {
		pixels[i] = other.pixels[i];
	}
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