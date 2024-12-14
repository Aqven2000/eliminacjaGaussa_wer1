#include <stdio.h>
#include "gaus.h"

double *initMatrixFromFile(char *fileName, int *r, int *c)
{
    FILE *file = fopen(fileName, "r");
    if (!file)
    {
        fprintf(stderr, "Cannot open file: %s\n", fileName);
        return NULL;
    }

    fscanf(file, "%d %d", r, c);
    double *mat = initMatrix(*c, *r);
    if (!mat)
    {
        fclose(file);
        return NULL;
    }

    for (int ir = 0; ir < *r; ir++)
    {
        for (int ic = 0; ic < *c; ic++)
        {
            fscanf(file, "%lf", &mat[ir * (*c) + ic]);
        }
    }

    fclose(file);
    return mat;
}
