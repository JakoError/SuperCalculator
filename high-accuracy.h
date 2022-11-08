//
// Created by violinwang on 2021/1/1.
//

#ifndef MAIN_5_C_HIGH_ACCURACY_H
#define MAIN_5_C_HIGH_ACCURACY_H

bool enter_to_high_accuracy();
bool add_calculate(char str[],int len);
int fnd_formula_split (char str[],int len) ;
void formula_split (char **p ,char* str,int len);
int get_cal_ans (char *p1,char *p2,int len1,int len2,int *ans);
void reverse(char *,int );
int max_common_calculate (int, int );
void save_to_Recording_1(char [],int * ,int);
int read_line (char str[],int n);
int Max(int,int);
#endif //MAIN_5_C_HIGH_ACCURACY_H
