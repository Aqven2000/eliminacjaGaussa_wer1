#include <stdio.h>
#include <stdlib.h>
#include "gaus.h"
int main()
{
    int r,c;
    printf("Podaj liczbe kolumn oraz wierszy macierzy: ");
    scanf("%d %d",&c,&r);
    double *matrix=initMatrix(c,r);
    double *res=initMatrix(1,r);

    fillMatrix(matrix,c,r);
    fillMatrix(res,1,r);
    
    printf("\nWczytana macierz:");
    printMatrix(matrix,c,r);
    printf("\n");
    printMatrix(res,1,r);
    printf("\n");

    elimGausa(matrix,res,c,r);
    //printf("\n");
    //printMatrix(matrix,c,r);
    //printf("\n");
    //printMatrix(res,1,r);

    toIdentityMatrix(matrix,res,c,r);//zrobic sprawdzanie czy jest wynik
    printf("\n");
    printf("Gausowana macierz:");
    printMatrix(matrix,c,r);
    printf("\n");
    if(isPossible(matrix,c,r)==0)
    {
        printf("Macierz nie jest mozliwa do rozwiazania");
        exit(1);
    }
    printMatrix(res,1,r);
    return 0;
}