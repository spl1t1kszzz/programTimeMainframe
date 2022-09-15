#include <iostream>
#include <cmath>

long double factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else {
        long double result = 1;
        for (int i = 1; i <= n; ++i)
            result *= i;
        return result;
    }
}

long double exponenta(long double x, int n) {
    long double result = 0;
    for (int i = 0; i < n; ++i) {
        result += pow(x,i) / (long double)factorial(i);
    }
    return result;
}

using namespace std;
int main() {
    return 0;
}