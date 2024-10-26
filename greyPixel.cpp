#include "greyPixel.h"
GreyPixel::GreyPixel():grey(100) {}
GreyPixel::GreyPixel(unsigned char grey):grey(grey) { }
GreyPixel::~GreyPixel() { }
unsigned char& GreyPixel::getGrey() {
	return grey;
}
