//
// Created by violinwang on 2021/1/5.
//

#ifndef MAIN_5_C_DEFINE_FIRST_H
#define MAIN_5_C_DEFINE_FIRST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_FORMU_LEN 10000
#define MAX_REC_NUM 10000
#define MAX_FILE_NAME_LEN 10
#define MAX_USER_NAME_LEN 30
#define STACK_SIZE 100
#define MAX_QSORT_N 100
#define MAX_LINE 100
#define false 0
#define true 1

typedef struct{
	double a;
	double b;
}plural;//复数类型声明
//a实部，b虚部

typedef struct  {
    int choice;
    union{
        struct {
            char formula[MAX_FORMU_LEN];
            int ans;
        }choi_0;

    	struct {
	        char formula[MAX_FORMU_LEN];
			int ans[MAX_FORMU_LEN];
			int ans_len;
		}choi_1;

		struct {
			int h;
			double a;
			double b;
		}choi_3;

		struct {
			int a,b,ans1,ans2;
		}choi_4;

		struct {
			double A[MAX_LINE][MAX_LINE];
			double B[MAX_LINE];
			double X[MAX_LINE];
			int NUM;
		}choi_5;

		struct {
			int n;
			int a[MAX_QSORT_N];
			int ans[MAX_QSORT_N];
		}choi_6;


		struct {
			int b,k,p,ans,jud;
		}choi_7;


		struct {
			plural A,B,answer;
			char tmp;
		}choi_8;

	};

}Recording;

#endif //MAIN_5_C_DEFINE_FIRST_H
