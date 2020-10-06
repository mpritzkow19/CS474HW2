#include <iostream>
#include <fstream>
#include <vector>
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
 int qValue;
 vector<int> values;

 // read image header
 readImageHeader(argv[1], N, M, Q, type);

 // allocate memory for the image array

 ImageType image(N, M, Q);

 char imageName[]= "peppers.pgm";
 readImage(imageName, image);

 cout << "Enter qValue: ";
 cin >> qValue;


 int divisor = 256 / qValue;
 int max_quantized_value = 255 / divisor;

 // threshold image

 for(i=0; i<N; i++)
   for(j=0; j<M; j++) {
     image.getPixelVal(i, j, val);
     int new_value = ((val / divisor) * 255) / max_quantized_value;
        values.push_back(new_value);
       image.setPixelVal(i, j, new_value);
     }

for(int i = 0; i < values.size(); i++){
  cout << values[i] << endl;
}
 // write image
 writeImage(argv[2], image);

 return (1);
}
