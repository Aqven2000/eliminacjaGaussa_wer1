#include "gaus.h"
#include <stdio.h>
#include <stdlib.h>

double *initMatrix(int c,int r)
{
    double *matrix=malloc(sizeof(double)*r*(c+1));//ostatnia kolumna bedzie na wyniki
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
    return matrix+id*c;
}
void multiplyRow(double *row,double val,int c)
{
    for(int i=0;i<c;i++)
        row[i]*=val;
}
void subRow(double *matrix,int id_1,int id_2,int c,int r)
{
    double *r1=getRow(matrix,id_1,c,r);
    double *r2=getRow(matrix,id_2,c,r);

    for(int i=0;i<c;i++)
        r1[i]-=r2[i];
}
void elimGausa(double *matrix,int c,int r)
{

    for(int i=0;i<c;i++)
    {
        double diag_val=matrix[i*c+i]; //watosc na diagonalnej
        for(int j=i+1;j<r;j++)
        {
            double factor=diag_val/matrix[j*c+i];
            multiplyRow(getRow(matrix,j,c,r),factor,c);
            //subRow
        }
    }
}