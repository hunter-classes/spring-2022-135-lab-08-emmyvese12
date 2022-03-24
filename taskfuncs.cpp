#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>
#include "imageio.h"
#include "taskfuncs.h"

//task A
//all colors are inverted (white to black OR black to white)
void invertColors(std::string imagefile, std::string outfile){
    // takes in a array called image, height, and width which are all empty and will be filled in with the image data
    int image[MAX_H][MAX_W];
    int height, width;
    readImage(imagefile, image, height, width); // reads the provided image and reports back the dimensions

    int out[MAX_H][MAX_W]; // modify the contents in a new array 

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){

            // (note: black is 0 & white is 255)
            // examples: 2 --> 253 3 --> 252 to do this: subtract the pixel by 255
            out[row][col] = 255 - (image[row][col]); // image[row][col] is the individual pixel brightness on a scale from 0 to 255 
            
        }
    }


    writeImage(outfile, out, height, width);
}

//task B
//inverts the colors ONLY in the right half of the picture

void invertColors2(std::string imagefile, std::string outfile){

    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    int halfMark = width/2;
    
    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){
            
            if (col >= halfMark){ //column number has to be greater than or equal to the half point mark to be on the right
                out[row][col] = 255 - (image[row][col]);
            }
            else { //if not, just keep it the same and copy it to array out
                out[row][col] = image[row][col];
            }
        }
    }

    writeImage(outfile, out, height, width);
}

