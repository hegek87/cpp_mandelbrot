CC=g++
OBJECTS=	bin/c_poly.o \
		bin/complex.o \
		bin/bitmap.o \
		bin/color.o \
		bin/draw_mandelbrot.o \
		bin/mandelbrot.o
CFLAGS=-c -g -Wall

all: bin/mandelbrot

bin/mandelbrot: $(OBJECTS)
	$(CC) $(OBJECTS) -o bin/mandelbrot

bin/complex.o:	../complex_num/complex.cpp
	$(CC) $(CFLAGS) ../complex_num/complex.cpp -o bin/complex.o
	
bin/c_poly.o:	../complex_poly/complex_poly.cpp
	$(CC) $(CFLAGS) ../complex_poly/complex_poly.cpp -o bin/c_poly.o
	
bin/bitmap.o:	../bitmap/bitmap.cpp
	$(CC) $(CFLAGS) ../bitmap/bitmap.cpp -o bin/bitmap.o
	
bin/color.o:	../color/color.cpp
	$(CC) $(CFLAGS) ../color/color.cpp -o bin/color.o
	
bin/draw_mandelbrot.o:	draw_mandelbrot.cpp ../bitmap/bitmap.hpp
	$(CC) $(CFLAGS) draw_mandelbrot.cpp -o bin/draw_mandelbrot.o
	
bin/mandelbrot.o:	mandelbrot.cpp
	$(CC) $(CFLAGS) mandelbrot.cpp -o bin/mandelbrot.o
	
clean:
	rm -f ./bin/*
