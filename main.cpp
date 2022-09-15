#include <iostream>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else {
        unsigned long long result = 1;
        for (int i = 1; i <= n; ++i)
            result *= i;
        return result;
    }
}

using namespace std;
int main() {
    cout<< factorial(6);
    return 0;
}