//
// Created by JakoError on 2020/12/29.
//
#pragma once
#ifndef MATRIX_MATRIX_C_H
#define MATRIX_MATRIX_C_H

#pragma warning (disable:4819)

#define MATRIX_MAX = 100;

/**
 *
 * #definition of matrix
 *
 * @matrix pointer of matrix
 * @m number of rows of the matrix
 * @n number of columns of the matrix
 * @name name of Matrix
 */
typedef struct {
    char *name;
    int m, n;
    double **table;
} Matrix;

void cpyArray(double **a,double **b,int m,int n);

#endif //MATRIX_MATRIX_C_H
