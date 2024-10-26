#ifndef ROTATOR_H
#define ROTATOR_H

#include <iostream>
#include <string>
class Rotator {
	private:
		Rotator();
		Rotator(const Rotator&) = delete;
		Rotator& operator=(const Rotator&)=delete;
		void skipComments(std::ifstream& file);
	public:
		static Rotator* getInstance();
		void rotateImage(const std::string& inputFile, const std::string& outputFile, int degrees);
};

#endif
