#include "gaus.h"
#include <stdio.h>
#include <stdlib.h>

double *initMatrix(int c,int r)
{
    double *matrix=malloc(sizeof(double)*r*c);
    if(matrix==NULL)
    {
        fprintf(stderr,"Alokacja pamieci sie wywalila");
        exit(1);
    }
    return matrix;
}
void fillMatrix(double *matrix,int c,int r)
{
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            //printf("%d",j*c+i);
            //scanf("%lf",&matrix[j*c+i]);
            matrix[j*c+i]=j*c+i+1;
        }
    }
}
void printMatrix(double *matrix,int c,int r)
{
    for(int i=0;i<r;i++)
    {
        printf("\n");
        for(int j=0;j<c;j++)
        {
            printf("%lf ",matrix[c*i+j]);
        }
    }
}
double *getRow(double *matrix,int id,int c,int r)
{
    if(id>r)
    {
        fprintf(stderr,"Bledy wiersz");
        return NULL;
    }
    return matrix+id*r;
}
void multiplyRow(double *row,double val,int c)
{
    for(int i=0;i<c;i++)
        row[i]*=val;
}