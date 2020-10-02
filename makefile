#CFLAGS = -g


% make
g++ -Wall -g -c Threshold.cpp
g++ -Wall -g   -c -o ReadImageHeader.o image.h ReadImageHeader.cpp
g++ -Wall -g   -c -o ReadImage.o image.h ReadImage.cpp
g++ -Wall -g   -c -o WriteImage.o image.h WriteImage.cpp
g++ -Wall -g -o main main.o Point.o Rectangle.o

ReadImageHeader.o:	image.h ReadImageHeader.cpp
	g++ -c -g ReadImageHeader.cpp

ReadImage.o:	image.h ReadImage.cpp
		g++ -c -g ReadImage.cpp

WriteImage.o:	image.h WriteImage.cpp
	g++ -c -g WriteImage.cpp

image.o:	image.h image.cpp
	g++ -c -g image.cpp

Threshold:	image.h image.o ReadImage.o ReadImageHeader.o WriteImage.o \
		Threshold.cpp
	g++ -o Threshold -g image.o ReadImage.o ReadImageHeader.o \
					WriteImage.o Threshold.cpp
