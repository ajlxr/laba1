#include <iostream>
#include "methods.h"

using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, eps;
    cout << "Ведите a, b, и eps: ";
    cin >> a >> b >> eps;

    double XDihotomia, XHorda, XNewton;
    int iterationsDihotomia = dihotomia(a, b, eps, XDihotomia);
    int iterationsHorda = horda(a, b, eps, XHorda);
    int iterationsNewton = newton(a, b, eps, XNewton);

    cout << "По методу Дихотомии:" << endl;
    cout << "Ответ: " << XDihotomia << endl;
  
    cout << "\nПо методу Хорды:" << endl;
    cout << "Ответ: " << XHorda << endl;
   
    cout << "\nПо методу Ньютона:" << endl;
    cout << "Ответ: " << XNewton << endl;

    return 0;
}