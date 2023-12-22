#include <iostream>
#include "methods.h"

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, eps;
    cout << "Ведите a, b, и eps: ";
    cin >> a >> b >> eps;

    double rootDihotomia, rootHorda, rootNewton;
    int iterationsDihotomia = dihotomia(a, b, eps, rootDihotomia);
    int iterationsHorda = horda(a, b, eps, rootHorda);
    int iterationsNewton = newton(a, b, eps, rootNewton);

    cout << "По методу Дихотомии:" << endl;
    cout << "Ответ: " << rootDihotomia << endl;
  
    cout << "\nПо методу Хорды:" << endl;
    cout << "Ответ: " << rootHorda << endl;
   
    cout << "\nПо методу Ньютона:" << endl;
    cout << "Ответ: " << rootNewton << endl;

    return 0;
}