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

    //gets input of sample rate from the user on the command line
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
    for (int i = 0; i < N; i += spResolution) { //used a double for loop in order to iterate properly through array
        for (int j = 0; j < M; j += spResolution) {
            image.getPixelVal(i, j, val);
            if (b <= newCol) //want to make sure that columns size of sub-sample array doesn't exceed limits (ie 128,64,32)
            {
                newArr[a][b] = val;
                cout << "Row: " << a << " Col: " << b << " New val: " << val << endl;
                b++;
            }
            else
            {
                if (a <= newRow)    //iterate to a new row once column has been fully explored
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


    //use another double for loop to display sub-sample array into the picture
    for (int i = 0; i < newRow; i++)
    {
        for (int j = 0; j < newCol; j++)
        {
            image.setPixelVal(i, j, newArr[i][j]); //insert correct sub-sample array value in the image
        }
    }
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
   
   // write image
   //writeImage(argv[2], image);
   writeImage(newLenna, image);

    return (1);
}

