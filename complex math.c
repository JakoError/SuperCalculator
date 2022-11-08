//
// Created by violinwang on 2021/1/5.
//

#include "Define_first.h"
#include "complex math.h"

extern int Currentcnt;
double a1_tmp, b1_tmp;

void Complex_cal (){
    all_save[++Currentcnt].choice = 8;
    printf ("\n请以a+bi的形式输入复数a： \n");
    char sa, sb;
    scanf("%lf%c%lfi", &a1_tmp, &sa, &b1_tmp);

    plural A;
    A.a = a1_tmp;
    if(sa == '+') A.b = b1_tmp;
    else A.b = (-b1_tmp);

    all_save[Currentcnt].choi_8.A=A;
    printf ("\n请以a+bi的形式输入复数b： \n");
    scanf("%lf%c%lfi", &a1_tmp, &sb, &b1_tmp);

    plural B;
    B.a = a1_tmp;
    if(sb == '+') B.b = b1_tmp;
    else B.b = (-b1_tmp);
    all_save[Currentcnt].choi_8.B=B;

    getchar();
    printf ("\n请以输入要对a和b进行的运算（+、-、*、/）： \n");
    char tmp;
    choose:
    scanf("%c", &tmp);
    plural answer;
    switch(tmp) {
        case '+':
            answer = plural_plus(A, B);
            break;
        case '-':
            answer = plural_less(A, B);
            break;
        case '*':
            answer = plural_multiple(A, B);
            break;
        case '/':
            answer = plural_devide(A, B);
            break;
        default:
            printf("\n请正确输入运算符号！\n");
            getchar();
            goto choose;
            break;

    }
    if(A.b > 0)
        printf("\n(%.2lf+%.2lfi) %c", A.a, A.b, tmp);
    else
        printf("\n(%.2lf%.2lfi) %c", A.a, A.b, tmp);
    if(B.b > 0)
        printf(" (%.2lf+%.2lfi) =", B.a, B.b);
    else
        printf(" (%.2lf%.2lfi) =", B.a, B.b);
    if(answer.b > 0)
        printf("%.2lf+%.2lfi", answer.a, answer.b);
    else
        printf("%.2lf%.2lfi", answer.a, answer.b);
    all_save[Currentcnt].choi_8.tmp = tmp;
    all_save[Currentcnt].choi_8.answer = answer;
}

plural plural_plus(plural m, plural n) {
    plural answer;
    answer.a = m.a + n.a;
    answer.b = m.b + n.b;
    return answer;
}//复数加


plural plural_less(plural m, plural n) {//m - n
    plural answer;
    answer.a = m.a - n.a;
    answer.b = m.b - n.b;
    return answer;
}//复数减


plural plural_multiple(plural m, plural n) {
    plural answer;
    answer.a = (m.a * n.a) - (m.b * n.b);
    answer.b = (m.a * n.b) + (m.b + n.a);
    return answer;
}//复数乘


plural plural_devide(plural m, plural n) {// m ÷n
    plural x, ans;
    int conplus = (n.a * n.a + n.b * n.b);
    x.a = n.a;
    x.b = n.b * (-1);
    ans = plural_multiple(x, m);
    ans.a /= conplus;
    ans.b /= conplus;
    return ans;
}//复数除