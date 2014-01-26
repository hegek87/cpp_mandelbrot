#include "mandelbrot.hpp"

int main(int argc, char **argv){
	char *fileName;
	if(argc == 2){
		fileName = argv[1];
	}
	else{
		fileName = (char *)"Mandelbrot.bmp";
	}
	Mandelbrot mb(TOLERANCE, WIDTH, HEIGHT);
	mb.generateImage();
	mb.getBitmap().createBMP(fileName);	
	return 0;
}
