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

vector<float> frequency2;
vector<int> imageData2;
vector<float> pmf2;
vector<float> cdf2;
vector<int> oldGreyLevel2;
vector<int> newGreyLevel2;

 int i, j;
 int M, N, Q;
 bool type;
 int val;
 int thresh;

 // read image header
 readImageHeader(argv[1], N, M, Q, type);

 // allocate memory for the image array
 ImageType image(N, M, Q);

//readImage
 char imageName[]= "f_16.pgm";
 readImage(imageName, image);

//put all pixel values into array
 for(i=0; i<N; i++)
   for(j=0; j<M; j++) {
     image.getPixelVal(i, j, val);
      imageData.push_back(val);
    }

//sort the array
sort(imageData.begin(), imageData.end());

//open file
ofstream fileOutput;
fileOutput.open("histogramData.txt", ios::out| ios::in);

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

//output data in the histogram
for(int i = 0; i < frequency.size(); i++){
  //cout << frequency[i] << endl;
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


//new image
char imageName2[]= "f_16.pgm";
readImage(imageName2, image);

//put all pixel values into array
 for(i=0; i<N; i++)
   for(j=0; j<M; j++) {
     image.getPixelVal(i, j, val);
      imageData2.push_back(val);
    }

//sort the array
sort(imageData2.begin(), imageData2.end());

//open file
//ofstream fileOutput;
//fileOutput.open("histogramData.txt", ios::out| ios::in);

//Count the frequency of items in the vector
vector<bool> visited2(imageData2.size(), false);

for (int i = 0; i < imageData2.size(); i++) {

    if (visited2[i] == true)
        continue;

    int count2 = 1;
    for (int j = i + 1; j < imageData2.size(); j++) {
        if (imageData2[i] == imageData2[j]) {
            visited2[j] = true;
            count2++;
        }
    }
    //fileOutput << imageData2[i]  << "  " << count2 << endl;
    frequency2.push_back(count);
    oldGreyLevel2.push_back(imageData2[i]);
  }

//output data in the histogram
for(int i = 0; i < frequency2.size(); i++){
  //cout << frequency[i] << endl;
}

//calculate pmf
for(int i = 0; i < frequency2.size(); i++){
  pmf2.push_back((frequency2[i]/imageData2.size()));
  //cout <<  setw(10) << pmf[i] << endl;
}

//calculate cdf
float sum2;
for(int i = 0; i < frequency2.size(); i++){
  sum2 += pmf2[i];
  cdf2.push_back(sum2);
  //cout <<  setw(10) << cdf[i] << endl;
}

//calculate new grey levels
for(int i = 0; i < oldGreyLevel2.size(); i++){
  newGreyLevel2.push_back(round(oldGreyLevel2[i] * cdf2[i]));
}

//mark 0's for any spot in which there is no

//Map the two images so that the grey levels are the same:
//use custom find function that will check all values
//check 1 to 255


/*
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
*/
 return (1);
}
