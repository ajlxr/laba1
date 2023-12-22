#include <iostream>
#include <cmath>
#include "methods.h"

double func(double x) {
    return log(pow(x, 3) + pow(x, 3) + cos(x));
}

int dihotomia(double a, double b, double eps, double& root) {
    int iterations = 0;
    while ((b - a) > eps) {
        root = (a + b) / 2;
        if (func(root) == 0.0) {
            return iterations;
        }
        else if (func(a) * func(root) < 0) {
            b = root;
        }
        else {
            a = root;
        }
        iterations++;
    }
    return iterations;
}

int horda(double a, double b, double eps, double& root) {
    int iterations = 0;
    do {
        root = a - (func(a) * (b - a)) / (func(b) - func(a));
        if (func(root) == 0.0) {
            return iterations;
        }
        else if (func(a) * func(root) < 0) {
            b = root;
        }
        else {
            a = root;
        }
        iterations++;
    } while (fabs(func(root)) > eps);
    return iterations;
}

int newton(double a, double b, double eps, double& root) {
    int iterations = 0;
    root = (a + b) / 2;
    do {
        root = root - func(root) / (4 * root * root * root * root + 3 * root * root - sin(root));
        iterations++;
    } while (fabs(func(root)) > eps);
    return iterations;
}