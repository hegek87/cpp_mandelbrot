#include <iostream>
#include "mandelbrot.hpp"


Mandelbrot::Mandelbrot(int tolerance){
	this->tolerance = tolerance;
}
		
std::vector<Color> Mandelbrot::getColorSet(){
	return this->colorSet;
}
/*
*  We will return a color based on the value of count after
*  the loop terminates. If count >= tolerance, return BLACK, 
*  otherwise we will return Color(count + 0x9F) [this return
*  value may change in the future]
*/
Color Mandelbrot::iteratePoly(Complex point){
	Complex polyDat[3] = {point,Complex(0,0),Complex(1,0)};
	ComplexPoly mbPoly(polyDat, 2);
	Complex iter = mbPoly.evaluate(ONE);
	int count = 0;
	while(iter.modulus() <= 2 && count < this->tolerance){
		iter = mbPoly.evaluate(iter);
		++count;
	}
	std::cout << count << std::endl;
	if(count >= this->tolerance){ return Color(0x000000); }
	return Color(count + 0x9F);
}

void Mandelbrot::generateColorSet(int width, int height){
	for(int i = 0; i < height; ++i){
		for(int j = 0; i < width; ++j){
			this->colorSet.push_back(this->iteratePoly(Complex(i, j)));
		}
	}
}
