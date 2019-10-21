#include <iostream>
#include <cmath>
#include "main.h"

/// Implements a function exp(−x*x).
/// \param x is the argument of the function.
/// \return a value of the function with the argument x.
double f(double x) {
    return exp(-x * x);
}

/// Integrate a function, which is hardcoded as f(double x).
/// \param a is a lower boundary of the interval.
/// \param b is an upper boundary of the interval.
/// \param n is a number of splits of the interval.
/// \return the integral of the function f(double x) in intervals [a, b] with integration number n.
double integral(double a, double b, int n) {
    double delta = (b - a) / n;
    double x0 = a;
    double x1 = a + delta;
    double x = x0 + delta / 2;
    double func = f(x);
    double s = delta * func;

    for (int i = 0; i < n - 1; ++i) {
        x0 = x1;
        x1 += delta;
        x = x0 + delta / 2;
        func = f(x);
        s += delta * func;
    }
    return s;
}

/// Tests the integral(double a, double b, int n) function
/// \return an error code.
int main() {
    std::cout << integral(0, 1, 1000000) << std::endl;
    return 0;
}
