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

//void swap(

/*int median(int nPar, int mPar, int N, int M, ImageType image, int val)
{
 //int arr[nPar][mPar];
 vector<int> temp;
 int val;
 int count = sizeof(arr)/sizeof(arr[0]);
 for(int i = 0; i < nPar; i++){
  for(int j = 0; j < mPar; j++){
        image.getPixelVal(N + i, M + j, val);
	//arr[nPar][mPar] = val;
 	temp.push_back(val);
  }
 }
 //sort(arr, count);
 //vecMed(temp);
 //return arr[i/2][j/2];
 return vecMed(temp);
}*/

/*int vecMed(vector<int> in){
 size_t size = in.size();
 
 sort(in.begin(), in.end());
 if(size % 2 == 0)
	return(in[size / 2 - 1] + in[size / 2]) / 2;
 else
 	return(in[size / 2]);
}
*/
int main(int argc, char *argv[])
{
 int i, j;
 int M, N, Q;
 bool type;
 int val;
 int qValue;
 vector<int> median;

 // read image header
 //readImageHeader("medianLenna.pgm", N, M, Q, type);
 readImageHeader("lenna.pgm", N, M, Q, type);

 // allocate memory for the image array

 ImageType image(N, M, Q);

 //char imageName[]= "medianLenna.pgm";
 char imageName[]= "lenna.pgm";
 readImage(imageName, image);

 /*//variables for median filter size
 int nPar;
 int mPar;

 cout << "Enter row size filter: ";
 cin >> nPar;

 cout << "Enter column size filter: ";
 cin >> mPar;
*/
 //int half = (N*M)/2;
 
 //salt the image
 /*int bOW = 2;
 for(int m = 0; m < half; m++)
 {
   int one = rand() % 255;
   int two = rand() % 255;
   image.getPixelVal(one, two, val);
   if(bOW % 2 == 0){
    image.setPixelVal(one, two, 255);
    bOW++;
   }
   else{
    image.setPixelVal(one, two, 0);
    bOW++;
   }
 }*/

 for(int i = 0; i < N; i++){
  for(int j = 0; j < M; j++){
	image.getPixelVal(i, j, val);
	median.push_back(val);
  }
 }

 cout << "Size: " << median.size() << endl;
 //int maskSize = nPar * mPar;
 //int placeholder = 0;
 
 /*//while(placeholder != values.size()){
  vector<int> maskVals;
 for(int i = placeholder; i < maskSize; i++){
   maskVals[i] = values[i];
 }
 sort(maskVals.begin(), maskVals.end());
 for(int b = 22; b < 27; b++)
 	cout << " " << maskVals[b];

 cout << vecMed(maskVals);
 //placeholder = placeholder + maskSize;
//}*/

 /*for(int i = 0; i < N; i++){
  for(int j = 0; j < M; j++){
    //image.setPixelVal(i, j, median(nPar,mPar,i,j, image, val));
    //int arr[nPar][mPar];
    //int count = sizeof(arr)/sizeof(arr[0]);
    //int count = sizeof(arr);
    vector<int> median;
    for(int a = 0; a < nPar; a++){
     for(int b = 0; b < mPar; b++){
	//arr[nPar][mPar] = image.getPixelVal(i + a, j + b, val);
        image.getPixelVal(i + a, j + b, val);
        median.push_back(val);
        if(a == nPar - 1 && b == mPar - 2){
	sort(median.begin(), median.end());
        image.setPixelVal(i, j, vecMed(median)); 
 	break;
        }
     }
    }
       
  }
 }*/

 // read image header
 readImageHeader("lenna.pgm", N, M, Q, type);

 // allocate memory for the image array

 ImageType image2(N, M, Q);

 char imageName2[]= "lenna.pgm";
 readImage(imageName2, image2);

 vector<int> original;

 for(int i = 0; i < N; i++){
  for(int j = 0; j < M; j++){
	image2.getPixelVal(i, j, val);
	original.push_back(val);
  }
 }

 vector<int> unsharp;

 for(int i = 0; i < N; i++){
  for(int j = 0; j < M; j++){
	//unsharp[i][j] = original[i][j] - median[i][j];
	//image2.setPixelVal(i, j, unsharp[i][j]);
  }
 }

 // write image
 writeImage("unsharpLenna.pgm", image2);

 return (1);
}
