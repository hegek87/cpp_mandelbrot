#include "mandelbrot.hpp"

int main(int argc, char **argv){
	
	char *fileName;
	if(argc == 2){
		fileName = argv[1];
	}
	else{
		fileName = (char *)"Mandelbrot.bmp";
	}
	//std::cout << "WIDTH: " << WIDTH << ", HEIGHT: " << HEIGHT << std::endl;
	std::ofstream writeFile;
	setupBMP(writeFile, fileName, WIDTH, HEIGHT);
	Mandelbrot mb(TOLERANCE);
//for(int i = 0; i < WIDTH*HEIGHT; ++i){ writeFile.write((char *)&RED, 3);}
	
	mb.generateColorSet(5,5);
	
	for(int i = 0; i < WIDTH*HEIGHT; ++i){
		Color rgb = mb.getColorSet()[i];
		int val = (rgb.getR())+(rgb.getG())+(rgb.getB());
		if(val != 0){
			std::cout << rgb << std::endl;
		}
		writeFile.write((char *)&val, 3);
	}
	
	
	return 0;
}
