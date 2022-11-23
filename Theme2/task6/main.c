#include <stdio.h>

#include "matrix.h"

int main() {

    printf("FILL FIRST MATRIX:\n");
    Matrix* matrix1 = newMatrix(2, 2);
    fillMatrixThroughTerminal(matrix1);
    printf("\n");

    printf("SAVE MATRIX TO FILE...\n");
    saveMatrixToFile(matrix1,"matrix.txt");

    printf("LOAD MATRIX FROM FILE...\n");
    Matrix* savedMatrix = loadMatrixFromFile("matrix.txt");

    printf("LOADED MATRIX:\n");
    printMatrix(savedMatrix);
    printf("\n");

    printf("FILL SECOND MATRIX:\n");
    Matrix* matrix2 = newMatrix(2, 2);
    fillMatrixThroughTerminal(matrix2);
    printf("\n");

    printf("FIRST MATRIX:\n");
    printMatrix(matrix1);
    printf("SECOND MATRIX:\n");
    printMatrix(matrix2);
    printf("\n");

    printf("SUM OF TWO MATRIX:\n");
    Matrix* sumMatrix = sum(matrix1, matrix2);
    printMatrix(sumMatrix);
    printf("\n");

    printf("SUBTRACTION OF MATRIX:\n");
    Matrix* subtractionMatrix = subtraction(matrix1, matrix2);
    printMatrix(subtractionMatrix);
    printf("\n");

    printf("USING SET MATRIX METHOD TO INDEX [0, 0] (1 time)\n");
    set(matrix1,0,0,1337);
    printf("ELEMENT WITH INDEXES [0, 0] is %.2lf\n\n", get(matrix1, 0, 0));

    printf("USING RESIZE MATRIX METHOD (2 times for 2 matrix)\n");
    resizeMatrix(matrix1,3,2);
    resizeMatrix(matrix2,2,3);

    printf("FIRST MATRIX\n");
    printMatrix(matrix1);
    printf("SECOND MATRIX\n");
    printMatrix(matrix2);
    printf("\n");

    printf("USING MULTIPLICATION MATRIX METHOD\n");
    Matrix* multiplicationMatrix = multiplication(matrix1,matrix2);

    printf("MULTIPLICATED MATRIX:\n");
    printMatrix(multiplicationMatrix);
    printf("\n");

    printf("USING MULTIPLICATION MATRIX BY NUMBER METHOD:\n");
    printf("MULTIPLICATED BY NUMBER MATRIX:\n");
    Matrix* multiplicationMatrixByNumber = multiplicationByNumber(matrix1,5);
    printMatrix(multiplicationMatrixByNumber);
    printf("\n");

    printf("USING CLEAR MATRIX (6 times)\n");
    clearMatrix(matrix1);
    clearMatrix(matrix2);
    clearMatrix(sumMatrix);
    clearMatrix(subtractionMatrix);
    clearMatrix(multiplicationMatrix);
    clearMatrix(multiplicationMatrixByNumber);

    return 0;
}