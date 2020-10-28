#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
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
 int thresh;

 // read image header
 readImageHeader(argv[1], N, M, Q, type);

 // allocate memory for the image array

 ImageType image(N, M, Q);

 char imageName[] = "sf.pgm";

  readImage(imageName, image);

//Read in the Sobel Y and then the Sobel x then add


  vector<vector<int> > Temp{{0, 1, 0},    //Laplacian
                              {1, -4, 1},
                              {0, 1, 0}};

vector<vector<int> > Temp2{{-1, -1, -1},    //Prewitt 1
                            {0, 0, 0},
                            {1, 1, 1}};

vector<vector<int> > Temp3{{-1, 0, -1},   //Prewitt 2
                            {-1, 0, 1},
                            {-1, 0, 1}};

vector<vector<int> > Temp4{{-1, -2, -1},  //Sobel 1
                            {0, 0, 0},
                            {1, 2, 1}};

vector<vector<int> > Temp5{{-1, 0, 1},  //Sobel 2
                            {-2, 0, 2},
                            {-1, 0, 1}};

//W = 9A-1
vector<vector<int> > Temp6{{-1, -1, -1},  //Sobel 2
                            {-1, 17, -1},
                            {-1, -1, -1}};

 // threshold image
int count = 0;
int matrix_size = 3;
int border = (matrix_size-1)/2;
int sum = 0;
queue<int> total;

//use all values in the NxN grid except the borders
for(int i=0; i<N-(matrix_size-1); i++){
  for(int j=0; j<M-(matrix_size-1); j++) {

    for(int k = 0; k < matrix_size; k++){
      for(int l = 0; l < matrix_size; l++){
        image.getPixelVal(i+k, j+l, val);
        sum += val * (Temp5[k][l]);
      }
    }
    total.push(sum);
    cout << sum/(matrix_size*matrix_size) << "value: " << count++ << endl;
    sum = 0;
  }
}

for(int i=border; i<N-border; i++){
  for(int j=border; j<M-border; j++) {

      image.setPixelVal(i, j, total.front());
      total.pop();

  }
}

 // write image
 writeImage(argv[2], image);

 return (1);
}
