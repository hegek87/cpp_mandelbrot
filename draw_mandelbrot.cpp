#include "mandelbrot.hpp"

int main(void){
	std::cout << "HI" << std::endl;
	Mandelbrot mb(1000);
	std::cout << mb.iteratePoly(Complex(-0.4,0.037)) << std::endl;
	return 0;
}
