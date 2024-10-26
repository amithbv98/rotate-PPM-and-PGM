#include <iostream>
#include "rotate.h"

int main(int argc, char* argv[]) {
	if (argc < 4) 
		std::cerr << "Usage: " << argv[0] << " <image_file> <output_file> <rotation_angle>" << std::endl;   
	std::string inputFile = argv[1]; 
	std::string outputFile = argv[2]; 
	int angle = std::stoi(argv[3]); 
	if (angle != 90 && angle != 180 && angle != 270) { 
		std::cerr << "Error: Rotation angle must be 90, 180, or 270 degrees." << std::endl; 
	}
	Rotator* rotate = Rotator::getInstance();
	rotate->rotateImage(inputFile, outputFile, angle);
	return 0;
}
	
