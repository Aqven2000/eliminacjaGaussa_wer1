#include "gaus.h"
#include <stdio.h>
#include <stdlib.h>

double *initMatrix(int c, int r)
{
    double *matrix = malloc(sizeof(double *) * r * c);
    if (matrix == NULL)
    {
        fprintf(stderr, "Alokacja pamieci sie wywalila");
        exit(1);
    }
    return matrix;
}
// void fillMatrix(double *matrix,int c,int r)
// {
//     for(int i=0;i<c;i++)
//     {
//         for(int j=0;j<r;j++)
//         {
//             scanf("%lf",&matrix[j*c+i]);
//         }
//     }
// }
void printMatrix(double *matrix, int c, int r)
{
    for (int i = 0; i < r; i++)
    {
        printf("\n");
        for (int j = 0; j < c; j++)
        {
            printf("%lf ", matrix[i * c + j]);
        }
    }
}

double *getRow(double *matrix, int id, int c, int r)
{
    if (id > r)
    {
        fprintf(stderr, "Bledy wiersz");
        return NULL;
    }
    return matrix + id * c;
}
void multiplyRow(double *row, double val, int c)
{
    for (int i = 0; i < c; i++)
        row[i] *= val;
}
void subRow(double *matrix, int id_1, int id_2, int c, int r)
{
    double *r1 = getRow(matrix, id_1, c, r);
    double *r2 = getRow(matrix, id_2, c, r);

    for (int i = 0; i < c; i++)
        r1[i] -= r2[i];
}

void swapRows(double *matrix, int id_1, int id_2, int c)
{
    double tmp;
    for (int i = 0; i < c; i++)
    {
        tmp = matrix[id_1 * c + i];
        matrix[id_1 * c + i] = matrix[id_2 * c + i];
        matrix[id_2 * c + i] = tmp;
    }
}

int isPossible(double *matrix, int c, int r)
{
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            if (j == i)
                continue;
            if (matrix[j * c + i] != 0)
                return 0;
        }
    }
    return 1;
}

void elimGausa(double *matrix, double *res, int c, int r)
{

    for (int i = 0; i < c; i++)
    {
        double diag_val = matrix[i * c + i]; // watosc na diagonalnej
        if (diag_val == 0.)
        {
            for (int k = i + 1; k < r; k++)
            {
                if (matrix[k * c + i] != 0)
                {
                    swapRows(matrix, i, k, c);
                    swapRows(res, i, k, 1);
                    break;
                }
            }
            diag_val = matrix[i * c + i];
            if (diag_val == 0)
            {
                fprintf(stderr, "Nie mozna znalezc niezerowego elementu na diagonali");
                exit(1);
            }
        }
        for (int j = i + 1; j < r; j++)
        {
            if (matrix[j * c + i] == 0)
                continue;
            double factor = diag_val / matrix[j * c + i];
            multiplyRow(getRow(matrix, j, c, r), factor, c);
            subRow(matrix, j, i, c, r);
            multiplyRow(getRow(res, j, 1, r), factor, 1);
            subRow(res, j, i, 1, r);
        }
    }
    for (int i = c - 1; i >= 0; i--)
    {
        double diag_val = matrix[i * c + i]; // watosc na diagonalnej
        for (int j = i - 1; j >= 0; j--)
        {
            double factor = diag_val / matrix[j * c + i];
            multiplyRow(getRow(matrix, j, c, r), factor, c);
            subRow(matrix, j, i, c, r);
            multiplyRow(getRow(res, j, 1, r), factor, 1);
            subRow(res, j, i, 1, r);
        }
    }
}

void toIdentityMatrix(double *matrix, double *res, int c, int r)
{
    for (int i = 0; i < r; i++)
    {
        if (matrix[i * c + i] == 0)
        {
            fprintf(stderr, "Nie można przeksztalcic macierzy na tozsamosciowa (zerowa wartość na diagonali w wierszu %d).\n", i);
            exit(0);
        }
        res[i] /= matrix[i * c + i];
        matrix[i * c + i] = 1;
    }
}