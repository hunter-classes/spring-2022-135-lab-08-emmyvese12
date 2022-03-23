#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <string>
#include "imageio.h"
#include "invertcolors.h"

//task A
void invertColors(std::string imagefile, std::string outfile){
    // takes in a array called image, height, and width which are all empty and will be filled in with the image data
    int image[MAX_H][MAX_W];
    int height, width;
    readImage(imagefile, image, height, width); // reads the provided image and reports back the dimensions

    int out[MAX_H][MAX_W]; // modify the contents in a new array 

    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            out[row][col] = 255 - (image[row][col]); // image[row][col] is the individual pixel brightness on a scale from 0 to 255 (note: black is 0 & white is 255)
        }
    }


    writeImage(outfile, out, height, width);
}