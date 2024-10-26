#include "rotate.h"
#include "ppm.h"
#include "pgm.h"
#include "colorPixel.h"
#include <fstream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <sstream>
#include<iostream>



Rotator::Rotator() { }

Rotator* Rotator::getInstance() {
 static Rotator* instance = new Rotator();
 return instance;
}

void Rotator::skipComments(std::ifstream& file) {
    char ch;
    file >> ch;
    while (ch == '#') {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        file >> ch;
    }
    file.putback(ch); 
}

void Rotator::rotateImage(const std::string& inputFile, const std::string& outputFile, int degrees) {
    std::ifstream fileHandle(inputFile);
	
    if (!fileHandle.is_open()) {
        throw std::runtime_error("Unable to open the file");
    }
    	
    std::string magicNumber;
    fileHandle >> magicNumber;
    skipComments(fileHandle);
    int width,height;
    fileHandle >> width >> height;
    skipComments(fileHandle);
    int maxVal;
    fileHandle >> maxVal;
   
        
    if (width <= 0 || height <= 0 || maxVal != 255) {
        throw std::runtime_error("The format of the file is invalid!");
    }
        
    if (!(magicNumber == "P2" || magicNumber == "P3" || magicNumber == "P5" || magicNumber == "P6")) {
        throw std::runtime_error("Format not supported!");
    }
        
    if(magicNumber == "P3" || magicNumber == "P6") {
    	
        std::vector<ColorPixel> input;
        input.resize(width * height);
        if(magicNumber == "P3") {
        	for(int i = 0; i < width * height; ++i) {
        	    int r, g, b;
        	    fileHandle >> r >> g >> b;
        	    input[i] = ColorPixel(static_cast<unsigned char>(r), static_cast<unsigned char>(g), static_cast<unsigned char>(b));
        	}
        	PPM p3 = PPM(width, height, maxVal, input);
       		p3.rotate(degrees);
       		p3.writeToP3File(outputFile);
        }
        else {
       		for(int i = 0; i < width * height; ++i) {
        	    input[i] = ColorPixel(static_cast<unsigned char>(fileHandle.get()), static_cast<unsigned char>(fileHandle.get()), static_cast<unsigned char>(fileHandle.get()));
        	}
        	PPM p6 = PPM(width, height, maxVal, input);
       		p6.rotate(degrees);
       		p6.writeToP6File(outputFile);
        }   	    
    }
    else {
        std::vector<GreyPixel> input;
        input.resize(width * height);
        
        if(magicNumber == "P2") {
            for(int i = 0; i < width * height; ++i) {
            	int g;
        	fileHandle >> g;
        	input[i] = GreyPixel(static_cast<unsigned char>(g));
            }
            
        	PGM p2 = PGM(width, height, maxVal, input);
       		p2.rotate(degrees);
       		p2.writeToP2File(outputFile);
        }
        else {
       	    for(int i = 0; i < width * height; ++i) {
        	input[i] = GreyPixel(static_cast<unsigned char>(fileHandle.get()));

            }
            PGM p5 = PGM(width, height, maxVal, input);
       	    p5.rotate(degrees);
       	    p5.writeToP5File(outputFile);
        }	
    }
}
        
        
        
        
        
