#include <stdio.h>
#include <math.h>
#include "gaus.h"
int compareResults(double *res, double *expected, int r) {
    for (int i = 0; i < r; i++) {
        if (fabs(res[i] - expected[i]) > 1e-6) return 0;
    }
    return 1;
}

void test1() {
    int c = 2, r = 2;
    double matrix[4] = {2, 3, 1, -1};
    double res[2] = {8, -1};
    double expected[2] = {1, 2};

    elimGausa(matrix, res, c, r);
    toIdentityMatrix(matrix, res, c, r);

    printf("Test 1: ");
    if (compareResults(res, expected, r)) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
    }
}

void test2() {
    int c = 3, r = 3;
    double matrix[9] = {2, 1, -1, -3, -1, 2, -2, 1, 2};
    double res[3] = {8, -11, -3};
    double expected[3] = {2, 3, -1};

    elimGausa(matrix, res, c, r);
    toIdentityMatrix(matrix, res, c, r);

    printf("Test 2: ");
    if (compareResults(res, expected, r)) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
    }
}

void test3() {
    int c = 3, r = 3;
    double matrix[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    double res[3] = {5, 7, 9};
    double expected[3] = {5, 7, 9};

    elimGausa(matrix, res, c, r);
    toIdentityMatrix(matrix, res, c, r);

    printf("Test 3: ");
    if (compareResults(res, expected, r)) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
    }
}

void test4() {
    int c = 3, r = 3;
    double matrix[9] = {0, 2, 3, 4, 5, 6, 7, 8, 0};
    double res[3] = {6, 15, 15};
    double expected[3] = {1, 1, 2};

    elimGausa(matrix, res, c, r);
    toIdentityMatrix(matrix, res, c, r);

    printf("Test 4: ");
    if (compareResults(res, expected, r)) {
        printf("✓ Passed\n");
    } else {
        printf("✗ Failed\n");
    }
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}