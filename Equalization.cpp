#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
#include<cmath>
#include<algorithm>

#include "image.h"
using namespace std;

int readImageHeader(char[], int&, int&, int&, bool&);
int readImage(char[], ImageType&);
int writeImage(char[], ImageType&);

int main(int argc, char *argv[])
{

vector<float> frequency;
vector<int> imageData;
vector<float> pmf;
vector<float> cdf;
vector<int> oldGreyLevel;
vector<int> newGreyLevel;

 int i, j;
 int M, N, Q;
 bool type;
 int val;
 int thresh;

 // read image header
 readImageHeader(argv[1], N, M, Q, type);

 // allocate memory for the image array
 ImageType image(N, M, Q);

 // read image
 char imageName[]= "f_16.pgm";
 readImage(imageName, image);

//put all pixel values into array
 for(i=0; i<N; i++)
   for(j=0; j<M; j++) {
     image.getPixelVal(i, j, val);
      imageData.push_back(val);
    }

//sort the vector
sort(imageData.begin(), imageData.end());

//open file
ofstream fileOutput;
fileOutput.open("histogramData.txt", ios::out| ios::trunc);

//Count the frequency of items in the vector
vector<bool> visited(imageData.size(), false);

for (int i = 0; i < imageData.size(); i++) {

    if (visited[i] == true)
        continue;

    int count = 1;
    for (int j = i + 1; j < imageData.size(); j++) {
        if (imageData[i] == imageData[j]) {
            visited[j] = true;
            count++;
        }
    }
    fileOutput << imageData[i]  << "  " << count << endl;
    frequency.push_back(count);
    oldGreyLevel.push_back(imageData[i]);
  }

//calculate pmf
for(int i = 0; i < frequency.size(); i++){
  pmf.push_back((frequency[i]/imageData.size()));
  //cout <<  setw(10) << pmf[i] << endl;
}

//calculate cdf
float sum;
for(int i = 0; i < frequency.size(); i++){
  sum += pmf[i];
  cdf.push_back(sum);
  //cout <<  setw(10) << cdf[i] << endl;
}

//calculate new grey levels
for(int i = 0; i < oldGreyLevel.size(); i++){
  newGreyLevel.push_back(round(oldGreyLevel[i] * cdf[i]));
}

//Map new grey levels onto photo
vector<int>::iterator found;
for(i=0; i<N; i++)
  for(j=0; j<M; j++) {
    image.getPixelVal(i, j, val);
    found = find(oldGreyLevel.begin(), oldGreyLevel.end(), val);
    if(found != oldGreyLevel.end()){
      image.setPixelVal(i, j, newGreyLevel[val]);
    }

   }
 // write image
 writeImage(argv[2], image);

 return (1);
}
