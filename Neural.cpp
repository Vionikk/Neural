#include <iostream>
#include <cmath>
#include <time.h>

double sigmoid(long double x) {
    return 1 / (1 + std::exp(-x));
}
double func(long double x[], long double y) {
    return x[0] * y + x[1] * y + x[2] * y;
}
int main() {
    long double t_in[3] = { 1, 1, 0 }, t_out = 1, w = -0.37543/*Случайные веса*/, out;
    for (long i1 = 0; i1 < 10000000000000000000000000000000000000; i1++) {
        out1 = sigmoid(func(t_in, w));
        w1 += func(t_in, (t_out - out) * out * (1 - out));
    }
    for (long i2 = 0; i2 < 10000000000000000000000000000000000000; i2++) {
        out2 = sigmoid(func(t_in, w));
        w2 += func(t_in, (t_out - out) * out * (1 - out));
    }
    for (long i3 = 0; i3 < 10000000000000000000000000000000000000; i3++) {
        out3 = sigmoid(func(t_in, w));
        w3 += func(t_in, (t_out - out) * out * (1 - out));
    }
    std::cout << out1 << std::endl;
    std::cout << out2 << std::endl;
    std::cout << out3 << std::endl;
}
