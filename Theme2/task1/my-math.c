#include <math.h>

double factorial(double x) {
    double sum = 1;
    int i;
    for (i = 1; i <= x; i++) {
        sum *= i;
    }
    return sum;
}

double my_sin(double x, double eps) {
    double addendum = __DBL_MAX__;
    double sum = 0;

    int i, degree;
    for (i = 0, degree = 1; fabsl(addendum) >= eps; i++, degree +=2){
        addendum = pow(x, degree) / factorial(degree) * pow(-1,i);
        sum += addendum;
    }

    return sum;
}

double my_cos(double x, double eps) {
    double addendum = __DBL_MAX__;
    double sum = 0;

    int i, degree;
    for (i = 0, degree = 0; fabsl(addendum) >= eps; i++, degree +=2){
        addendum = pow(x, degree) / factorial(degree) * pow(-1, i);
        sum += addendum;
    }

    return sum;
}
