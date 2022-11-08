//
// Created by JakoError on 2020/12/17.
//
#pragma once
#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#pragma warning (disable:4819)

#include "hashMap.h"
#include "matrix_c.h"

#define MATRIX_NAME_MAX 50

void matrixMain();

Matrix createMatrix(int m, int n, double **table);

/**
 * #mode for read matrix and save it to parameters
 */
void matrixMain();

Matrix readMatrix(const char *line);

int equal(const char *line);

char *operate(char *line);

int nextIndex(const char *line,int i);
/**
 * #add function
 */
Matrix addM(Matrix *a, Matrix *b);

Matrix invM(Matrix *a);
/**
 * #minus function
 */
Matrix minusM(Matrix *a, Matrix *b);

/**
 * #multiple function
 */
Matrix mulM(Matrix *a, Matrix *b);

/**
 * divide function
 */
//Matrix divM(Matrix *a, Matrix *b);

/**
 * involution function
 */
//Matrix powerM(Matrix *a, Matrix *b);

/**
 * #.multiple function
 */
//Matrix pmulM(Matrix *a, Matrix *b);

/**
 * #.divide function
 */
//Matrix pdivM(Matrix *a, Matrix *b);

/**
 * #.^ power funtion
 */
//Matrix ppower(Matrix *a, Matrix *b);

Matrix eye(int m);
Matrix fill(double num,int m, int n);
Matrix randi(int Maxi, int m, int n);
Matrix diag(double *nums, int length);

void printMatrix(Matrix m);
#endif //MATRIX_MATRIX_H
