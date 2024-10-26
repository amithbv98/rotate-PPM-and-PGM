#ifndef GREYPIXEL_H
#define GREYPIXEL_H

class GreyPixel {
	private:
		unsigned char grey;
	public:
		GreyPixel();
		GreyPixel(unsigned char grey);
		~GreyPixel();
		unsigned char& getGrey();
};

#endif
