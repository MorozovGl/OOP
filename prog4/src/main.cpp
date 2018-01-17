#include <iostream>
#include <fstream>
#include "PrimeFactoring.h"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cerr << "Arguments error" << std::endl;
        return 0;
    }

    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);


    if (!(fin.is_open() && fout.is_open())) {
        std::cerr << "Can't open files." << std::endl;
        return 0;
    }

    uint64_t cur_value;
    while (fin >> cur_value) {
        if (cur_value <= UINT64_MAX && cur_value > 0) {
            PrimeFactors pf(cur_value);
            fout << cur_value << " = " << pf.ToString() << std::endl;
        }
    }

    fout << std::endl;

    fin.close();
    fout.close();
    return 0;
}