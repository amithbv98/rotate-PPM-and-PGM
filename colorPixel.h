#ifndef COLORPIXEL_H
#define COLORPIXEL_H

class ColorPixel {
	private:
		unsigned char red;
		unsigned char green;
		unsigned char blue;
	public:
		ColorPixel();
		ColorPixel(unsigned char red, unsigned char green, unsigned char blue);
		~ColorPixel();
		unsigned char& getRed();
		unsigned char& getGreen();
		unsigned char& getBlue();
};

#endif
