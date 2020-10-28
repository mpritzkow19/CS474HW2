#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <stdlib>

#include "image.h"
using namespace std;

int readImageHeader(char[], int&, int&, int&, bool&);
int readImage(char[], ImageType&);
int writeImage(char[], ImageType&);

int main(int argc, char *argv[])
{

//char * argv = new char[30];
//cin >> argv;

 int i, j;
 int M, N, Q;
 bool type;
 int val;
 int val2;
 int thresh;

 // read image header
 readImageHeader(argv[1], N, M, Q, type);

 // allocate memory for the image array

 ImageType image(N, M, Q);

  ImageType image2(N, M, Q);

 char imageName[] = "lenna.pgm";

 char imageName2[] = "lenna.pgm";

  readImage(imageName, image);
  readImage(imageName2, image2);
 // threshold image

 for(i=0; i<N; i++)
   for(j=0; j<M; j++) {
     image.getPixelVal(i, j, val);
     image2.getPixelVal(i, j, val2);
       image.setPixelVal(i, j, abs((val+val2)-255));
    }

 // write image
 writeImage(argv[2], image);

 return (1);
}
