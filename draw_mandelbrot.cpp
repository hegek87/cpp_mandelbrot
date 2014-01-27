#include "mandelbrot.hpp"

int main(int argc, char **argv){
	char *fileName = ((argc==2) ? argv[1] : (char *)"Mandelbrot.bmp");
	Mandelbrot mb(TOLERANCE, WIDTH, HEIGHT);
	mb.generateImage();
	mb.getBitmap().createBMP(fileName);
	return 0;
}
