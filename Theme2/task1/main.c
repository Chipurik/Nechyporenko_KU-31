#include "my-math.h"
#include <stdio.h>
#include <math.h>

double curveFunction(double x);
double distanceBetweenPoints(double x1, double y1, double x2, double y2);

double EPS = 0.0001;

int main() {

    printf("5! : %.2lf\n", factorial(5));
    printf("2^3 : %.2lf\n", pow(2,3));

    printf("sin(1) : %lf\n", my_sin(1, EPS));
    printf("cos(1) : %lf\n", my_cos(1, EPS));
    printf("f(x) : %lf\n", curveFunction(1));

    int from, to, count;

    printf("Enter from: ");
    scanf("%d", &from);
    printf("Enter to: ");
    scanf("%d", &to);
    printf("Enter count: ");
    scanf("%d", &count);

    double stepLength = (double)(to - from) / count;

    double curveLength = 0;
    double currentPos = from;

    int i;
    for (i = 0; i < count; i++){
        curveLength += distanceBetweenPoints(currentPos, curveFunction(currentPos), currentPos - stepLength, curveFunction(currentPos + stepLength));
        currentPos += stepLength;
    }

    printf("Curve length: %lf\n", curveLength);

    return 0;
}

double curveFunction(double x){
    return pow(my_sin(x, EPS),2) / (1 + pow(my_cos(x, EPS),3));
}

double distanceBetweenPoints(double x1, double y1, double x2, double y2){
    return sqrt(pow((x2 - x1),2) + pow((y2 - y1), 2)) ;
}
