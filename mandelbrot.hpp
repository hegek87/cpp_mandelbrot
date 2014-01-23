#ifndef MANDELBROT_H
#define MANDELBROT_H
#include "../complex_poly/complex_poly.h"
#include "../complex_num/complex.h"
#include "../bitmap/bitmap.hpp"
#include "../color/color.h"
#include <vector>

#define TOLERANCE 1000

const Complex unity(1,0);

class Mandelbrot{
	private:
		std::vector<Color> colorSet;
		int tolerance;
	public:
		Mandelbrot(int);
		
		Color iteratePoly(Complex);
		void generateColorSet(int, int);
		const std::vector<Color>& getColorSet();
};
#endif
