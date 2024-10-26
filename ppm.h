#ifndef PPM_H
#define PPM_H
#include <vector>
#include "colorPixel.h"
#include <string>
#include<fstream>

class PPM {
	private:
		int width;
		int height;
		int max_size;
		std::vector<ColorPixel> pixels;
		std::vector<ColorPixel> output;
		int angle;
	public:
		PPM();
		PPM(int& width, int& height, int& max_size, std::vector<ColorPixel>& pixels);
		~PPM();
		int getWidth();
		int getHeight();
		int getSize();
		
		void writeToP3File(const std::string& fileName);
		void writeToP6File(const std::string& fileName);
		void rotate(int degrees); 
};
	
#endif	
