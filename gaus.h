#ifndef _GAUS_H_
#define _GAUS_H_

double *initMatrix(int,int);
void fillMatrix(double *,int,int);
void printMatrix(double *,int,int);
double *getRow(double *,int,int,int);
void multiplyRow(double *,double,int);
void subRow(double *,int,int,int,int);
void elimGausa(double *,int,int);

#endif