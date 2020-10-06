CFLAGS = -g

ReadImage.o:	image.h ReadImage.cpp
	g++ -c $(CFLAGS) ReadImage.cpp

ReadImageHeader.o:	image.h ReadImageHeader.cpp
	g++ -c $(CFLAGS) ReadImageHeader.cpp

WriteImage.o:	image.h WriteImage.cpp
	g++ -c $(CFLAGS) WriteImage.cpp

image.o:	image.h image.cpp
	g++ -c $(CFLAGS) image.cpp

all:	image.h image.o ReadImage.o ReadImageHeader.o WriteImage.o \
		Equalization.cpp Quantization.cpp Sampling.cpp
	g++ -o Equalization $(CFLAGS) image.o ReadImage.o ReadImageHeader.o \
					WriteImage.o Equalization.cpp
	g++ -o Quantization $(CFLAGS) image.o ReadImage.o ReadImageHeader.o \
					WriteImage.o Quantization.cpp
	g++ -o Sampling $(CFLAGS) image.o ReadImage.o ReadImageHeader.o \
					WriteImage.o Sampling.cpp
