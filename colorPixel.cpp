#include "colorPixel.h"

ColorPixel::ColorPixel():red(0), green(0), blue(0) {
}

ColorPixel::ColorPixel(unsigned char red, unsigned char green, unsigned char blue):red(red),green(green), blue(blue) {
}

ColorPixel::~ColorPixel() {
}

unsigned char& ColorPixel::getRed() {
	return this->red;
}

unsigned char& ColorPixel::getGreen() {
	return this->green;
}

unsigned char& ColorPixel::getBlue() {
	return this->blue;
}
