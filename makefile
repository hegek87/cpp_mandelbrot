all:
	g++ -c -g -Wall ../complex_num/complex.cpp -o ./bin/complex.o
	g++ -c -g -Wall ../complex_poly/complex_poly.cpp -o ./bin/c_poly.o
	g++ -c -g -Wall ../bitmap/bitmap.cpp -o ./bin/bitmap.o
	g++ -c -g -Wall ../color/color.cpp -o ./bin/color.o
	
	g++ -c -g -Wall draw_mandelbrot.cpp -o ./bin/draw_mandelbrot.o	
	g++ -c -g -Wall mandelbrot.cpp -o ./bin/mandelbrot.o
	g++ -o ./bin/mandelbrot ./bin/*.o