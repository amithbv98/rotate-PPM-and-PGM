#include "pgm.h"
PGM::PGM() : width(0), height(0), max_size(0), pixels() {
}

PGM::PGM(int& width, int& height, int& max_size, std::vector<GreyPixel>& pixels) : width(width), height(height), max_size(max_size), pixels(pixels) {
}

int& PGM::getWidth() {
	return this->width;
}

int& PGM::getHeight() {
	return this->height;
}

int& PGM::getSize() {
	return this->max_size;
}

PGM::~PGM() { }

void PGM::writeToP2File(const std::string& fileName) {
    std::ofstream file(fileName);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing!");
    }

    if(angle == 180) {
    	file << "P2\n" << width << " " << height << "\n" << max_size << "\n";
    }
    else {
    	file << "P2\n" << height << " " << width << "\n" << max_size << "\n";
    }
    for (int i = 0; i < width * height; ++i) {
        file << static_cast<int>(output[i].getGrey()) << "\n";
    }
    if (file.fail()) {
        throw std::runtime_error("Error writing pixel data!");
    }
}

void PGM::writeToP5File(const std::string& fileName) {
    std::ofstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Cannot open file for writing!");
    }

    if(angle == 180) {
    	file << "P5\n" << width << " " << height << "\n" << max_size << "\n";
    }
    else {
    	file << "P5\n" << height << " " << width << "\n" << max_size << "\n";
    }
    for (int i = 0; i < width * height; ++i) {
        file.write(reinterpret_cast<const char*>(&(output[i].getGrey())), sizeof(output[i].getGrey()));
    }
    if (file.fail()) {
        throw std::runtime_error("Error writing pixel data!");
    }
}

void PGM::rotate(int degrees) {
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
