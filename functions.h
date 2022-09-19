#ifndef PROGRAMTIMEMAINFRAME_FUNCTIONS_H
#define PROGRAMTIMEMAINFRAME_FUNCTIONS_H

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
    for (int i = 0; i < n; ++i)
        result += pow(x,i) / (long double)factorial(i);
    return result;
}

void clkGetTime(long double x, int n) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    exponenta(x, n);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("Time taken: %lf sec.\n", end.tv_sec-start.tv_sec+ 0.000000001*(end.tv_nsec-start.tv_nsec));
}

#endif //PROGRAMTIMEMAINFRAME_FUNCTIONS_H
