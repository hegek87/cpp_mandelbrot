#ifndef MANDELBROT_H
#define MANDELBROT_H
#include "../complex_poly/complex_poly.h"
#include "../complex_num/complex.h"
#include "../bitmap/bitmap.hpp"
#include "../color/color.h"
#include <vector>

#define TOLERANCE 150

const Complex unity(1,0);

class Mandelbrot{
	private:
		Bitmap bmp;
		int tolerance;
	public:
		Mandelbrot(int, int, int);
		
		Color iteratePoly(Complex);
		void generateImage();
		Bitmap& getBitmap();
};
#endif
