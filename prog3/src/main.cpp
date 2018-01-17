#include <iostream>
#include "wav.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        Wav w("../0.wav");
        w.PrintInfo();
        w.MakeReverb(0.500, 0.6f);
        w.MakeWavFile("rev.wav");
    }
    catch (WavException &e) {
        std::cout << e.what();
    }
    return 0;
}