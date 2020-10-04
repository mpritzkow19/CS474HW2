#include <iostream>
#include <fstream>
#include <vector>

#include "image.h"
using namespace std;

int readImageHeader(char[], int&, int&, int&, bool&);
int readImage(char[], ImageType&);
int writeImage(char[], ImageType&);

int main(int argc, char* argv[])
{

    int i, j;
    int M, N, Q;
    bool type;
    int val;

    //User selected resolution input (either 2,4,or 8)
    int spResolution;

    //output filename
    char newLenna[] = "newLenna.pgm";

    vector<int> sampleData;

    // read image header
    readImageHeader(argv[1], N, M, Q, type);

    // allocate memory for the image array

    ImageType image(N, M, Q);

    // read image
    readImage(argv[1], image);

    cout << "Options for spatial resolution factor: 2, 4, 8" << endl;
    cout << "Enter Spatial Resolution desired: ";
    cin >> spResolution;

    //check if input = 2, 4, or 8
    if (spResolution == 2 || spResolution == 4 || spResolution == 8)
    {
        cout << "Accepted input" << endl;
    }
    else
    {
        cout << "Invalid input" << endl;
        return 0;
    }
    /*
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
    */

    //desired sub-sampled array size
    int newRow = (N / spResolution);
    int newCol = (M / spResolution);
    //variables that will keep index of sub-sampled array
    int a = 0;
    int b = 0;
    //Matrix to store the sub-sample
    int newArr[newRow][newCol];

    cout << "Right before loop starts." << endl;

    //for loop that will populate sub-sample with correct values
    for (int i = 0; i < N; i += spResolution) {
        for (int j = 0; j < M; j += spResolution) {
            image.getPixelVal(i, j, val);
            if (b <= newCol)
            {
                newArr[a][b] = val;
                cout << "Row: " << a << " Col: " << b << " New val: " << val << endl;
                b++;
            }
            else
            {
                if (a <= newRow)
                {
                    a++;
                }
                b = 0;
            }
        }
        cout << "VALUE OF I: " << i << endl;
        cout << "VALUE OF J: " << j << endl;
    }
    cout << "Made it past the for loops" << endl;
    cout << "newRow: " << newRow << endl;

    /*
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
    */
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
   //writeImage(argv[2], image);
   //writeImage(newLenna, image);

    return (1);
}

