CC=g++
OBJECTS= bin/c_poly.o bin/complex.o  bin/bitmap.o bin/color.o bin/draw_mandelbrot.o bin/mandelbrot.o
CFLAGS=-c -g -Wall

all: mandelbrot

mandelbrot: .$(OBJECTS)
	$(CC) $(OBJECTS) -o ./bin/mandelbrot

./bin/complex.o:
	$(CC) $(CFLAGS) ../complex_num/complex.cpp -o ./bin/complex.o
	
.bin/c_poly.o:
	$(CC) $(CFLAGS) ../complex_poly/complex_poly.cpp -o ./bin/c_poly.o
	
./bin/bitmap.o:
	$(CC) $(CFLAGS) ../bitmap/bitmap.cpp -o ./bin/bitmap.o
	
./bin/color.o:
	$(CC) $(CFLAGS) ../color/color.cpp -o ./bin/color.o
	
./bin/draw_mandelbrot.o:
	$(CC) $(CFLAGS) draw_mandelbrot.cpp -o ./bin/draw_mandelbrot.o
	
./bin/mandelbrot.o:
	$(CC) $(CFLAGS) mandelbrot.cpp -o ./bin/mandelbrot.o
	
clean:
	rm -f ./bin/*
