#include <iostream>
#include <fstream>
#include <vector>

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
 int spResolution;

 vector<int> sampleData;

 // read image header
 readImageHeader(argv[1], N, M, Q, type);

 // allocate memory for the image array

 ImageType image(N, M, Q);

 // read image
 readImage(argv[1], image);

cout << "Options for spatial resolution factor: 2, 4, 8";
cout << "Enter Spatial Resolution desired: ";
cin >> spResolution;

//sample the Image by taking every other number from every other row
for(i=0; i<N; i++)
  for(j=0; j<M; j++) {
    image.getPixelVal(i, j, val);
      if(i % 2 == 0){
        if(j % 2 == 0){
          sampleData.push_back(val);
        }
      }
  }

//resize image by countdown
int rowCount = spResolution;
int columnCount = spResolution;
int pos = 0;

  for(i=0; i<N; i++){
    image.setPixelVal(i, j, sampleData[pos]);

   if(columnCount ==0){
     columnCount = spResolution;
     //pos++;
   }
   columnCount--;

    for(j=0; j<M; j++) {
      image.setPixelVal(i, j, sampleData[pos]);

     if(rowCount ==0){
       rowCount = spResolution;
      pos++;
     }
     rowCount--;

    }
  }

 // threshold image
/*
 for(i=0; i<N; i++)
   for(j=0; j<M; j++) {
     image.getPixelVal(i, j, val);
     if(val < thresh)
       image.setPixelVal(i, j, 255);
     else
       image.setPixelVal(i, j, 0);
    }
*/
 // write image
 writeImage(argv[2], image);

 return (1);
}
