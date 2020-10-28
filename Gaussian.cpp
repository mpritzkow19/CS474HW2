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

 char imageName[] = "lenna.pgm";

  readImage(imageName, image);

  vector<vector<double> > Temp{{1, 1, 2, 2, 2, 1, 1},
                                {1, 2, 2, 4, 2, 2, 1},
                                {2, 2, 4, 8, 4, 2, 2},
                                {2, 4, 8, 16, 8, 4, 2},
                                {2, 2, 4, 8, 4, 2, 2},
                                {1, 2, 2, 4, 2, 2, 1},
                                {1, 1, 2, 2, 2, 1, 1}};
//131

  vector<vector<double> > Temp2{{2, 2, 3, 4, 5, 5, 6, 6, 6, 5, 5, 4, 3, 2, 2},
                                {2, 3, 4, 5, 7, 7, 8, 8, 8, 7, 7, 5, 4, 3, 2},
                                {3, 4, 6, 7, 9, 10, 10, 11, 10, 10, 9, 7, 6, 4, 3},
                                {4, 5, 7, 9, 10, 12, 13, 13, 13, 12, 10, 9, 7, 5, 4},
                                {5, 7, 9, 11, 13, 14, 15, 16, 15, 14, 13, 11, 9, 7, 5},
                                {5, 7, 10, 12, 14, 16, 17, 18, 17, 16, 14, 12, 10, 7, 5},
                                {6, 8, 10, 13, 15, 17, 19, 19, 19, 17, 15, 13, 10, 8, 6},
                                {6, 8, 11, 13, 16, 18, 19, 20, 19, 18, 16, 13, 11, 8, 6},
                                {6, 8, 10, 13, 15, 17, 19, 19, 19, 17, 15, 13, 10, 8, 6},
                                {5, 7, 10, 12, 14, 16, 17, 18, 17, 16, 14, 12, 10, 7, 5},
                                {5, 7, 9, 11, 13, 14, 15, 16, 15, 14, 13, 11, 9, 7, 5},
                                {4, 5, 7, 9, 10, 12, 13, 13, 13, 12, 10, 9, 7, 5, 4},
                                {3, 4, 6, 7, 9, 10, 10, 11, 10, 10, 9, 7, 6, 4, 3},
                                {2, 3, 4, 5, 7, 7, 8, 8, 8, 7, 7, 5, 4, 3, 2},
                                {2, 2, 3, 4, 5, 5, 6, 6, 6, 5, 5, 4, 3, 2, 2}};

//2044
 // threshold image
int count = 0;
int matrix_size = 7;
int border = (matrix_size-1)/2;
double sum = 0;
queue<int> total;

//use all values in the NxN grid except the borders
for(int i=0; i<N-(matrix_size-1); i++){
  for(int j=0; j<M-(matrix_size-1); j++) {

    for(int k = 0; k < matrix_size; k++){
      for(int l = 0; l < matrix_size; l++){
        image.getPixelVal(i+k, j+l, val);
        sum += val * (Temp2[k][l]/(500));
      }
    }
    total.push((int)round(sum));
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
