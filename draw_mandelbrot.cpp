#include "mandelbrot.hpp"

int main(int argc, char **argv){
	char *fileName;
	if(argc == 2){
		fileName = argv[1];
	}
	else{
		fileName = (char *)"Mandelbrot.bmp";
	}
	std::ofstream writeFile;
	setupBMP(writeFile, fileName, WIDTH, HEIGHT);
	Mandelbrot mb(TOLERANCE);
	//mb.iteratePoly(Complex(.245, -.56));
	
	mb.generateColorSet(WIDTH, HEIGHT);
	
	for(int i = 0; i < (WIDTH*HEIGHT); ++i){
		Color rgb = mb.getColorSet()[i];
		writeFile.put(rgb.getR());
		writeFile.put(rgb.getG());
		writeFile.put(rgb.getB());
	}
	
	
	return 0;
}
