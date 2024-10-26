#include "ppm.h"
#include <stdexcept>

PPM::PPM() : width(0), height(0), max_size(0) {
}

PPM::PPM(int& width, int& height, int& max_size, std::vector<ColorPixel>& pixels) : width(width), height(height), max_size(max_size),pixels(pixels) {
}

int PPM::getWidth() {
	return this->width;
}

int PPM::getHeight() {
	return this->height;
}

int PPM::getSize() {
	return this->max_size;
}

PPM::~PPM() { }



void PPM::writeToP3File(const std::string& fileName) {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing!");
    }

    if(angle == 180) {
    	file << "P3\n" << width << " " << height << "\n" << max_size << "\n";
    }
    else {
    	file << "P3\n" << height << " " << width << "\n" << max_size << "\n";
    }
    for (int i = 0; i < width * height; ++i) {
        file << static_cast<int>(output[i].getRed()) << "\n";
        file << static_cast<int>(output[i].getGreen()) << "\n";
        file << static_cast<int>(output[i].getBlue()) << "\n";
    }
    if (file.fail()) {
        throw std::runtime_error("Error writing pixel data!");
    }
}

void PPM::writeToP6File(const std::string& fileName) {
    std::ofstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing!");
    }
    if(angle == 180) {
    	file << "P6\n" << width << " " << height << "\n" << max_size << "\n";
    }
    else {
    	file << "P6\n" << height << " " << width << "\n" << max_size << "\n";
    }
    for (int i = 0; i < width * height; ++i) {
        file.write(reinterpret_cast<const char*>(&(output[i].getGreen())), sizeof(output[i].getRed()));
        file.write(reinterpret_cast<const char*>(&(output[i].getRed())), sizeof(output[i].getGreen()));
        file.write(reinterpret_cast<const char*>(&(output[i].getBlue())), sizeof(output[i].getBlue()));
    }
    if (file.fail()) {
        throw std::runtime_error("Error writing pixel data!");
    }
}

void PPM::rotate(int degrees) {
    angle = degrees;
    output.resize(height * width);
    if(degrees == 90) {
    	for (int y = 0; y < height; ++y) {
        	for (int x = 0; x < width; ++x) {
            		output[x * height + (height - 1 - y)] = pixels[y * width + x];
        	}
    	}
    }
    else if(degrees == 180) {
    	for (int x = 0; x < width; ++x) {
        	for (int y = 0; y < height; ++y) {
        	    output[y * width + x] = pixels[(height - 1 -y) * width + (width - 1 - x)];
        	}
    	}
    }
    else {
        for (int y = 0; y < height; ++y) {
        	for (int x = 0; x < width; ++x) {
            		output[(width - 1 - x) * height + y] = pixels[y * width + x];
        	}
    	}
    }
}


	


