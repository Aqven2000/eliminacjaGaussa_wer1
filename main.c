#include <stdio.h>
#include "gaus.h"
int main()
{
    int r,c;
    printf("Podaj liczbe kolumn oraz wierszy macierzy: ");
    scanf("%d %d",&c,&r);
    int *matrix=initMatrix(c,r);
    fillMatrix(matrix,c,r);
    printMatrix(matrix,c,r);


    return 0;
}