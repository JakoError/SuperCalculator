//
// Created by violinwang on 2021/1/1.
//

#include "Define_first.h"
#include "tri-math functions.h"

const double pi = 3.1415926;
const double eps = 0.0000001;
extern Recording all_save[MAX_REC_NUM];
extern int Currentcnt;

void tri_math_cal(){
    double a, b, c, d, e, f, g;
    int h;
    printf("���ԽǶ�������һ���Ƕ�:\t");
    scanf("%lf",&a);
    printf("�������ң�������1\t");
    printf("�������ң�������2\n");
    printf("�������У�������3\t");
    printf("�������������4\n");
    printf("������������5\t");
    printf("�������У�������6\n");
    scanf("%d",&h);
    b = sin (a * pi / 180);
    c = cos (a * pi / 180);
    d = tan (a * pi / 180);
    if (a>=90-eps && a<=90+eps && h==3){
        printf ("----��ֵ������----\n");
        return ;
    }
    e = 1/b;
    f = 1/c;
    g = 1/d;
    switch(h){
        case 1:
            printf("sin(%.2lf��)=%.2lf\n",a,b);
            save_to_Recording_3(a,b);
            break;
        case 2:
            printf("cos(%.2lf��)=%.2lf\n",a,c);
            save_to_Recording_3(a,c);
            break;
        case 3:
            printf("tan(%.2lf��)=%.2lf\n",a,d);
            save_to_Recording_3(a,d);
            break;
        case 4:
            printf("sec(%.2lf��)=%.2lf\n",a,e);
            save_to_Recording_3(a,e);
            break;
        case 5:
            printf("csc(%.2lf��)=%.2lf\n",a,f);
            save_to_Recording_3(a,f);
            break;
        case 6:
            printf("cot(%.2lf)=%.2lf\n",a,g);
            save_to_Recording_3(a,g);
            break;
    }
    return ;
}

void save_to_Recording_3(double a,double b){
    all_save[++Currentcnt].choice = 3;
    all_save[Currentcnt].choi_3.a=a;
    all_save[Currentcnt].choi_3.b=b;
    return ;
}
