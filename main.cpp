#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"
#include "invertcolors.h"

int main(){

    //task A invert colors
    std::string imageFile = "image1.pgm";
    std::string taskA_outfile = "taskA.pgm";
    invertColors(imageFile, taskA_outfile); // on mac--> open taskA.pgm OR qlmanage -p taskA.pgm


    return 0;
}
