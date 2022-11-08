//
// Created by violinwang on 2021/1/1.
//

#include "Define_first.h"
#include "Gauss-Jordan Elimination.h"

extern Recording all_save[MAX_REC_NUM];
extern int Currentcnt;
double A[MAX_LINE][MAX_LINE],B[MAX_LINE];

void Input_Matrix()//输入矩阵
{
    all_save[++Currentcnt].choice = 5;
    int i,j;
    printf("系数矩阵A的阶数:\n");
    scanf("%d",&all_save[Currentcnt].choi_5.NUM);
    for(i=0; i<all_save[Currentcnt].choi_5.NUM; i++)
    {
        printf("系数矩阵A的第%d行元素:\n",i+1);
        for(j=0; j<all_save[Currentcnt].choi_5.NUM; j++){
            scanf("%lf",&all_save[Currentcnt].choi_5.A[i][j]);
            A[i][j] = all_save[Currentcnt].choi_5.A[i][j];
        }

    }
    printf("右端项b:\n");
    for(i=1; i<=all_save[Currentcnt].choi_5.NUM; i++)
    {
        scanf("%lf",&all_save[Currentcnt].choi_5.B[i-1]);
        B[i-1] = all_save[Currentcnt].choi_5.B[i-1];
    }

    printf("\n增广矩阵[A,b]为:\n");
    for(i=0; i<all_save[Currentcnt].choi_5.NUM; i++)
    {
        for(j=0; j<all_save[Currentcnt].choi_5.NUM; j++)
            printf("%.2lf\t",all_save[Currentcnt].choi_5.A[i][j]);
        printf("%.2lf\t", all_save[Currentcnt].choi_5.B[i]);
        printf("\n");
    }
    printf("\n");
    Gauss();
    return ;
}

void Gauss()
{
    int i,j,k,column;
    double max,A_temp,B_temp,mik,sum;
    for(k=0; k<all_save[Currentcnt].choi_5.NUM-1; k++)
    {
        column=k;
        max=0;
        for(i=k; i<all_save[Currentcnt].choi_5.NUM; i++)
        {
            if(fabs(A[i][k])>max)
            {
                max=fabs(A[i][k]);
                column=i;
            }
        }
        for(j=k; j<all_save[Currentcnt].choi_5.NUM; j++)
        {
            A_temp = A[k][j];
            A[k][j] = A[column][j];
            A[column][j] = A_temp;
        }
        B_temp = B[k];
        B[k] = B[column];
        B[column] = B_temp;
        for(i=k+1; i<all_save[Currentcnt].choi_5.NUM; i++)//消元过程
        {
            mik = A[i][k]/A[k][k];
            for(j=k; j<all_save[Currentcnt].choi_5.NUM; j++)
                A[i][j]-=mik*A[k][j];
            B[i]-= mik*B[k];
        }

    }
    all_save[Currentcnt].choi_5.X[all_save[Currentcnt].choi_5.NUM-1]=B[all_save[Currentcnt].choi_5.NUM-1]/A[all_save[Currentcnt].choi_5.NUM-1][all_save[Currentcnt].choi_5.NUM-1];
    for(i=all_save[Currentcnt].choi_5.NUM-2; i>=0; i--)
    {
        sum = 0;
        for(j=i+1; j<all_save[Currentcnt].choi_5.NUM; j++)
            sum+=A[i][j]*all_save[Currentcnt].choi_5.X[j];
        all_save[Currentcnt].choi_5.X[i]=(B[i]-sum)/A[i][i];
    }
    printf("结果X:\n");
    for(i=0; i<all_save[Currentcnt].choi_5.NUM; i++)
        printf("x%d=%.2lf\n",i+1,all_save[Currentcnt].choi_5.X[i]);
    return ;

}