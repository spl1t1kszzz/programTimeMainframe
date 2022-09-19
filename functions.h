#ifndef PROGRAMTIMEMAINFRAME_FUNCTIONS_H
#define PROGRAMTIMEMAINFRAME_FUNCTIONS_H
#include <sys/times.h>
#include <unistd.h>

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
    struct timespec start{}, end{};
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    exponenta(x, n);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("Time taken: %lf sec.\n", (double)end.tv_sec-(double)start.tv_sec+ 0.000000001*(double )(end.tv_nsec-start.tv_nsec));
}


void getTimes(long double x, int n) {
    struct tms start{}, end{};
    long cps = sysconf(_SC_CLK_TCK);
    unsigned long long clocks;
    times(&start);
    exponenta(x, n);
    times(&end);
    clocks = end.tms_utime - start.tms_utime;
    printf("Time taken: %lf sec.\n", (double)clocks / (double )cps);
}

#endif //PROGRAMTIMEMAINFRAME_FUNCTIONS_H
