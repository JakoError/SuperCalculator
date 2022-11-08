//
// Created by violinwang on 2021/1/5.
//

#include "Define_first.h"
#include "Greatest Common Divisor & Least Common Multiple.h"

extern Recording all_save[MAX_REC_NUM];
extern int Currentcnt;

void GCD_LCM(){
    all_save[++Currentcnt].choice = 4;
    printf("\n请输入两个数（空格相隔）: ");
    scanf("%d%d",&all_save[Currentcnt].choi_4.a,&all_save[Currentcnt].choi_4.b);
    all_save[Currentcnt].choi_4.ans1 = max_common_calculate(all_save[Currentcnt].choi_4.a,all_save[Currentcnt].choi_4.b);
    all_save[Currentcnt].choi_4.ans2 = all_save[Currentcnt].choi_4.a*all_save[Currentcnt].choi_4.b/all_save[Currentcnt].choi_4.ans1;
    printf("\n%d 和 %d 的最大公约数为%d  ",all_save[Currentcnt].choi_4.a,all_save[Currentcnt].choi_4.b,all_save[Currentcnt].choi_4.ans1);
    printf("最小公倍数为%d\n",all_save[Currentcnt].choi_4.ans2);
}

int max_common_calculate (int a,int b){
    int s=b;
    while(a%b!=0)
    {
        s=a%b;
        a=b;
        b=s;
    }
    return s;
}
