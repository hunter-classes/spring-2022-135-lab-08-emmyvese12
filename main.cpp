#include <iostream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"
#include "taskfuncs.h"

int main(){

    //task A invert colors
    std::string imageFile = "image1.pgm";
    std::string taskA_outfile = "taskA.pgm";
    invertColors(imageFile, taskA_outfile); // on mac--> open taskA.pgm OR qlmanage -p taskA.pgm

    //task B invert right half only
    std::string taskB_outfile = "taskB.pgm";
    invertColors2(imageFile, taskB_outfile);

    return 0;
}
