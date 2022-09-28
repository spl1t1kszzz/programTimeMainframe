#include <iostream>
#include "functions.h"
#include <cmath>
using namespace std;
int main(int argc, char* argv[]) {
    if (argc < 4)
        throw std::invalid_argument("invalid number of arguments");
    int timer = atoi(argv[3]);
    long double x = (long double)(atoi(argv[1]));
    int n = atoi(argv[2]);
    switch (timer){
        case 0:
            cout<<exponenta(x,n)<<endl;
            break;
        case 1:
            clkGetTime(x,n);
            break;
        case 2:
            getTimes (x,n);
            break;
        default:
            throw std::invalid_argument("invalid argument");
            break;

    }
    return 0;
}