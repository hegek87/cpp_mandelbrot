#include <iostream>
#include "mandelbrot.hpp"


Mandelbrot::Mandelbrot(int tolerance){
	this->tolerance = tolerance;
}
static int inSet = 0;
static int outSet = 0;
/*
*  We will return a color based on the value of count after
*  the loop terminates. If count >= tolerance, return BLACK, 
*  otherwise we will return Color(count + 0x99) 
*  	[this return value may change in the future]
*/
Color Mandelbrot::iteratePoly(Complex point){
	Complex polyDat[3] = {point,Complex(0,0),Complex(1,0)};
	ComplexPoly mb(polyDat, 2);
	Complex iter = mb.evaluate(ZERO);
	int count = 0;
	while(iter.modulus() <= 2 && count < this->tolerance){
		iter = mb.evaluate(iter);
		++count;
	}
	if(count >= this->tolerance){
		++inSet;
		return Color(0x000000);
	}
	else{ 
		++outSet;
		return Color(count);
	}
}

void Mandelbrot::generateColorSet(int width, int height){
	for(int i = -height/2; i < height/2; ++i){
		for(int j = -width/2; j < width/2; ++j){
			double xPixel = ((double)(4*i)/width);
			double yPixel = ((double)(4*j)/height);
			//std::cout << "X: " << xPixel;
			//std::cout << ", Y: " << yPixel << std::endl;
			Complex pixel(xPixel, yPixel);
			Color pColor = this->iteratePoly(pixel);
			this->colorSet.push_back(pColor);
		}
	}
	std::cout << "In the set: " << inSet << std::endl;
	std::cout << "Out of the set: " << outSet << std::endl;
}

const std::vector<Color>& Mandelbrot::getColorSet(){ return colorSet; }
