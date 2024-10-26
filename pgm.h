#ifndef PGM_H
#define PGM_H

#include "greyPixel.h"
#include <stdexcept>
#include<vector>
#include<fstream>
class PGM {
	private:
		int angle;
		int width;
		int height;
		int max_size;
		std::vector<GreyPixel> pixels;
		std::vector<GreyPixel> output;
	public:
		PGM();
		PGM(int& width, int& height, int& max_size, std::vector<GreyPixel>& pixels);
		~PGM();
		int& getWidth();
		int& getHeight();
		int& getSize();
		void writeToP2File(const std::string& fileName);
		void writeToP5File(const std::string& fileName);
		void rotate(int degrees); 
};

#endif
