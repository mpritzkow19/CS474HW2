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
	Combo.cpp Gaussian.cpp Mean.cpp Laplacian.cpp
	g++ -o Combo $(CFLAGS) image.o ReadImage.o ReadImageHeader.o \
					WriteImage.o Combo.cpp
	g++ -o Gaussian $(CFLAGS) image.o ReadImage.o ReadImageHeader.o \
					WriteImage.o Gaussian.cpp
	g++ -o Mean $(CFLAGS) image.o ReadImage.o ReadImageHeader.o \
					WriteImage.o Mean.cpp
	g++ -o Laplacian $(CFLAGS) image.o ReadImage.o ReadImageHeader.o \
					WriteImage.o Laplacian.cpp
