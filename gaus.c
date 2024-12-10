#include "gaus.h"
#include <stdio.h>
#include <stdlib.h>

int *initMatrix(int c,int r)
{
    int *matrix=malloc(sizeof(int)*r*c);
    if(matrix==NULL)
    {
        fprintf(stderr,"Alokacja pamieci sie wywalila");
        exit(1);
    }
    return matrix;
}
void fillMatrix(int *matrix,int c,int r)
{
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            printf("%d",j*c+i);
            scanf("%d",&matrix[j*c+i]);
        }
    }
}
void printMatrix(int *matrix,int c,int r)
{
    for(int i=0;i<r;i++)
    {
        printf("\n");
        for(int j=0;j<c;j++)
        {
            printf("%d ",matrix[c*i+j]);
        }
    }
}
int *getRow(int *matrix,int id,int c,int r)
{
    if(id>r)
    {
        fprintf(stderr,"Bledy wiersz");
        return NULL;
    }
    int *row=malloc(sizeof(int)*c);
    for(int i=0;i<c;i++)
        row[i]=matrix[id*c+i];
    return row;
}
void multiplyRow(int *row,int val,int c)
{
    for(int i=0;i<c;i++)
        row[i]*=val;
}