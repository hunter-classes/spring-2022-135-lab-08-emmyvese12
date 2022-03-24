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


//task C
//add a white box exactly in the middle of the picture 

void whiteBox(std::string imagefile, std::string outfile){

    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    int colMark1 = width/4; // quarter of the width (left side of the box)
    int colMark2 = 3 * colMark1; // 3/4 of the width (right side of the box)

    int rowMark1 = height/4; // quarter of the height (top of the box)
    int rowMark2 = 3 * rowMark1; // 3/4 of the height (bottom of the box)

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){

            // greater than or equal to mark 1 and below mark 2 which is going from 1/4 to 3/4 == 1/2
            if ( (col >= colMark1 && col < colMark2) && (row >= rowMark1 && row < rowMark2) ){
                int diff = 255 - image[row][col]; // to be white, the pixel brightness needs to be 255, so we calculate the difference then add that back
                out[row][col] = diff + (image[row][col]);
            }
            else {
                out[row][col] = image[row][col];
            }
        }
    }

    writeImage(outfile, out, height, width);

}


//task D
//add a frame (one pixel thick) in the middle of the picture

void addFrame(std::string imagefile, std::string outfile){
    
    int image[MAX_H][MAX_W];
    int height, width;

    readImage(imagefile, image, height, width);

    int out[MAX_H][MAX_W];
    int colMark1 = width/4; // quarter of the width (left side of the box)
    int colMark2 = 3 * colMark1; // 3/4 of the width (right side of the box)

    int rowMark1 = height/4; // quarter of the height (top of the box)
    int rowMark2 = 3 * rowMark1; // 3/4 of the height (bottom of the box)

    for (int row = 0; row < height; row++){
        for (int col = 0; col < width; col++){

            // top horizontal line must be on rowMark1 and can span through the columns
            // left vertical line must be on colMark1 and can span through all the rows
            // (same applies for right line and bottom line)

            // the column must be in between the column range and must belong on either marked row
            if ( (col >= colMark1 && col < colMark2) && (row == rowMark1 || row == rowMark2) ){
                int diff = 255 - image[row][col];
                out[row][col] = diff + image[row][col];
            }
            else if ( (row >= rowMark1 && row < rowMark2) && (col == colMark1 || col == colMark2) ){
                int diff = 255 - image[row][col];
                out[row][col] = diff + image[row][col];
            }
            else {
                out[row][col] = image[row][col];
            }
        }
    }

    writeImage(outfile, out, height, width);

}