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
long double average(long double a, long double b, long double c, long double d){
    long double t = 4.0;
    return (a+b+c+d)/t;
}
int main() {
    long double t_in1[3] = { 1, 0, 0 }, t_out1 = 1, w1 = -0.37543/*Випадкові ваги*/;
    long double t_in2[3] = { 1, 1, 0 }, t_out2 = 1, w2 = -0.37543/*Випадкові ваги*/;
    long double t_in3[3] = { 1, 1, 1 }, t_out3 = 1, w3 = -0.37543/*Випадкові ваги*/;
    long double t_in4[3] = { 1, 1, 1 }, t_out4 = 1, w4 = -0.37543/*Випадкові ваги*/;
    //long double t_in5[3] = { 1, 1, 1 }, t_out5 = 1, w5 = -0.37543/*Випадкові ваги*/, out5;
    for (long i1 = 0; i1 < 21474836464; i1++) {
        long double out1 = sigmoid(func(t_in1, w1));
        w1 += func(t_in1, (t_out1 - out1) * out1 * (1 - out1));
    }
    for (long i2 = 0; i2 < 21474836463; i2++) {
        long double out2 = sigmoid(func(t_in2, w2));
        w2 += func(t_in2, (t_out2 - out2) * out2 * (1 - out2));
    }
    for (long i3 = 0; i3 < 21474836462; i3++) {
        long double out3 = sigmoid(func(t_in3, w3));
        w3 += func(t_in3, (t_out3 - out3) * out3 * (1 - out3));
    }
    for (long i4 = 0; i4 < 21474836461; i4++) {
        long double out4 = sigmoid(func(t_in4, w4));
        w4 += func(t_in4, (t_out4 - out4) * out4 * (1 - out4));
    }
    /*for (long i5 = 0; i5 < 21474836460; i5++) {
        out5 = sigmoid(func(t_in5, w5));
        w5 += func(t_in5, (t_out5 - out5) * out5 * (1 - out5));
    }*/
    long double avearge = average(out1, out2, out3, out4);
    
    //std::cout << out1 << std::endl;
    //std::cout << out2 << std::endl;
    //std::cout << out3 << std::endl;
    //std::cout << out4 << std::endl;
    //std::cout << out5 << std::endl;
    //std::cout << average << std::endl;
}

