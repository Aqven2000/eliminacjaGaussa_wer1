#include <stdio.h>
#include <stdlib.h>
#include "gaus.h"
int main()
{
    int r,c;
    printf("Podaj liczbe kolumn oraz wierszy macierzy: ");
    scanf("%d %d",&c,&r);
    double *matrix=initMatrix(c,r);
    fillMatrix(matrix,c,r);
    printMatrix(matrix,c,r);
    printf("\n");
    //multiplyRow(getRow(matrix,0,c,r),2.0,c);
    //printMatrix(matrix,c,r);
    subRow(matrix,0,1,c,r);
    printf("\n");
    printMatrix(matrix,c,r);
    return 0;
}