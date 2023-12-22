#include <iostream>
#include <cmath>
#include "methods.h"

double func(double x) {
    return log(pow(x, 3) + pow(x, 3) + cos(x));
}

int dihotomia(double a, double b, double eps, double& X) {
    int iterations = 0;
    while ((b - a) > eps) {
        X = (a + b) / 2;
        if (func(X) == 0.0) {
            return iterations;
        }
        else if (func(a) * func(X) < 0) {
            b = X;
        }
        else {
            a = X;
        }
        iterations++;
    }
    return iterations;
}

int horda(double a, double b, double eps, double& X) {
    int iterations = 0;
    do {
        X = a - (func(a) * (b - a)) / (func(b) - func(a));
        if (func(X) == 0.0) {
            return iterations;
        }
        else if (func(a) * func(X) < 0) {
            b = X;
        }
        else {
            a = X;
        }
        iterations++;
    } while (fabs(func(X)) > eps);
    return iterations;
}

int newton(double a, double b, double eps, double& X) {
    int iterations = 0;
    X = (a + b) / 2;
    do {
        X = X - func(X) / (4 * pow(X, 4) + 3 * pow(X, 2) - sin(X));
        iterations++;
    } while (fabs(func(X)) > eps);
    return iterations;
}