#include <iostream>
#include <cmath>
#include <time.h>
//Vionikk
double sigmoid(long double x) {
    return 1 / (1 + std::exp(-x));
}
double func(long double x[], long double y) {
    return x[0] * y + x[1] * y + x[2] * y;
}
int main() {
    long double t_in1[3] = { 1, 1, 0 }, t_out1 = 1, w1 = -0.37543/*Случайные веса*/, out1;
    long double t_in2[3] = { 1, 1, 0 }, t_out2 = 1, w2 = -0.37543/*Случайные веса*/, out2;
    long double t_in3[3] = { 1, 1, 1 }, t_out3 = 1, w3 = -0.37543/*Случайные веса*/, out3;
    for (long i1 = 0; i1 < 100000000; i1++) {
        out1 = sigmoid(func(t_in1, w1));
        w1 += func(t_in1, (t_out1 - out1) * out1 * (1 - out1));
    }
    for (long i2 = 0; i2 < 200000000; i2++) {
        out2 = sigmoid(func(t_in2, w2));
        w2 += func(t_in2, (t_out2 - out2) * out2 * (1 - out2));
    }
    for (long i3 = 0; i3 < 200000000; i3++) {
        out3 = sigmoid(func(t_in3, w3));
        w3 += func(t_in3, (t_out3 - out3) * out3 * (1 - out3));
    }
}
