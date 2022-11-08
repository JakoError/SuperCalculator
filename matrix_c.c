//
// Created by JakoError on 2020/12/29.
//
#include <stdlib.h>
#include <stdio.h>

//double ***getTable(int m, int n) {
//    if (!m || !n)
//        return NULL;
//    static double **p;
//    p = (double **) malloc(sizeof(double *) * 3);
//    for (int i = 0; i < 3; ++i) {
//        p[i] = malloc(sizeof(double) * 3);
//    }
//    return &p;
//}

void cpyArray(double **a, double **b, int m, int n) {
    if (a == NULL){
        printf("??????????????????????????????");
        return;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = b[i][j];
        }
    }
}
