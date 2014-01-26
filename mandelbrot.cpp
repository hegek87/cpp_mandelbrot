#include <iostream>
#include <cmath>
#include "mandelbrot.hpp"


Mandelbrot::Mandelbrot(int tolerance, int width, int height) 
: bmp(width, height){
	this->tolerance = tolerance;
}

static int inSet = 0;
static int outSet = 0;
/*
*  We will return a color based on the value of count after
*  the loop terminates. If count >= tolerance, return BLACK, 
*  otherwise we will return a color based on count. We use 
*  log properties to make the color change fade smoothly.
*/
Color Mandelbrot::iteratePoly(Complex point){
	Complex polyDat[3] = {point,Complex(0,0),Complex(1,0)};
	ComplexPoly mb(polyDat, 2);
	Complex iter = mb.evaluate(ZERO);
	int count = 0;
	while(iter.modSquared() <= 4 && count < this->tolerance){
		iter = mb.evaluate(iter);
		++count;
	}
	if(count >= this->tolerance){
		++inSet;
		return Color(0x000000);
	}
	else{ 
		++outSet;
		int fadeColor = 1 + count - (double)(log(log(iter.modulus()))/log(2));
		return Color(fadeColor<<2);
	}
}

void Mandelbrot::generateImage(){
	int width = bmp.getIHeader().width, height = bmp.getIHeader().height;
	for(int i = -height/2; i < height/2; ++i){
		for(int j = -width/2; j < width/2; ++j){
			double xPixel = ((double)(4*i)/width);
			double yPixel = ((double)(4*j)/height);
			Complex pixel(xPixel, yPixel);
			Color pColor = this->iteratePoly(pixel);
			this->bmp.setPixel(i+(height/2), j+(width/2), pColor);
		}
	}
	std::cout << "In the set: " << inSet << std::endl;
	std::cout << "Out of the set: " << outSet << std::endl;
}

Bitmap& Mandelbrot::getBitmap(){ return this->bmp; }
