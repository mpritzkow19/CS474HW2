#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
//#include <bits/stc++.h>

#include "image.h"
using namespace std;

int readImageHeader(char[], int&, int&, int&, bool&);
int readImage(char[], ImageType&);
int writeImage(char[], ImageType&);

int main(int argc, char *argv[])
{
 int i, j;
 int M, N, Q;
 bool type;
 int val;
 int qValue;
 
//vectors for both mask and the actual image
 vector<int> mask;
 vector<int> fullImage;

 // read image header of pattern
 readImageHeader("Pattern.pgm", N, M, Q, type);

 // allocate memory for the image array
 ImageType imageMask(N, M, Q);

 char imageName[]= "Pattern.pgm";
 readImage(imageName, imageMask);

 // allocate memory for the image array
 ImageType imageFull(A, B, Z);
 // read image header for Image
 readImageHeader("Image.pgm", A, B, Z, type);

 // allocate memory for the image array
 ImageType imageFull(A, B, Z);

 char imageName2[]= "Image.pgm";
 readImage(imageName2, imageFull);

//store correct values in imageMask
 for(int i = 0; i < N; i++){
  for(int j = 0; j < M; j++){
	imageMask.getPixelVal(i, j, val);
	mask.push_back(val);
  }
 }

//store correct values in fullImage
 for(int i = 0; i < A; i++){
  for(int j = 0; j < B; j++){
	imageMask.getPixelVal(i, j, val);
	fullImage.push_back(val);
  }
 }

 int halfMask = M / 2;
 int halfImage = B / 2;

 //vector that will store final correlation values
 vector<int> correlation;

//implement the equation from Fig 1.
 for(int i = 0; i < N; i++){
  for(int j = 0; j < halfMask; j++){
	correlation[i][j] = (mask[i][j])(fullImage[i][j]);
	imageFull.setPixelVal(i, j, correlation[i][j]);
  }
 }

 // write image
 writeImage("correlation.pgm", imageFull);

 return (1);
}
