#include "gaus.h"
#include <stdio.h>
#include <stdlib.h>

int **initMatrix(int c,int r)
{
    int **matrix=mallloc(sizeof(int*)*c);
    for(int i=0;i<c;i++)
        matrix[i]=calloc(r,sizeof(int));
    if(matrix==NULL)
        fprintf(stderr,"Blad w alokacji matrix-u");
}
void fillMatrix(int **matrix,int c,int r)
{
    for(int i=0;i<c;i++)
        for(int j=0;j<r;j++)
            scanf("%d",matrix[i][j]);
}
void printMatrix(int **matrix,int c,int r)
{
    for(int i=0;i<c;i++)
    {
        printf("\n");
        for(int j=0;j<r;j++)
            printf("%d ",matrix[i][j]);
    }

}