//
// Created by violinwang on 2021/1/5.
//

#include "Define_first.h"
#include "quick_pow.h"

extern Recording all_save[MAX_REC_NUM];
extern int Currentcnt;

void quick_pow(){
    printf("\n������������a^b%%c,������a�� \n");
    int a_tmp, b_tmp, c_tmp,ans;
    scanf("%d", &a_tmp);
    printf("������b�� \n");
    scanf("%d", &b_tmp);
    printf("������c�� \n");
    scanf("%d", &c_tmp);
    if (b_tmp==0){
        printf("%d��%d�η���%dȡ��Ĵ�Ϊ: 1", a_tmp, b_tmp, c_tmp);
        save_to_Recording_7(a_tmp,b_tmp,c_tmp,1,1);
        return ;
    }

    if(b_tmp <= 0){
        ans = POW(a_tmp, -b_tmp, c_tmp);
        printf("%d��%d�η���%dȡ��Ĵ�Ϊ:1/%ld", a_tmp, b_tmp, c_tmp, ans);
        save_to_Recording_7(a_tmp,b_tmp,c_tmp,ans,0);
    }

    else{
        ans = POW(a_tmp, b_tmp, c_tmp);
        printf("%d��%d�η���%dȡ��Ĵ�Ϊ:%ld", a_tmp, b_tmp, c_tmp, ans);
        save_to_Recording_7(a_tmp,b_tmp,c_tmp,ans,1);
    }

}

long POW(long w, int b, int p) {
    w %= p;
    long ans = 1;
    while(b > 0) {
        if(b % 2 != 0) {
            ans = (ans * w) % p;
            ans %= p;
        }
        w = w * w % p;
        b = b / 2;
    }
    return ans % p;
}

void save_to_Recording_7(int b,int k,int p,int ans,int jud){
    all_save[++Currentcnt].choice = 7;
    all_save[Currentcnt].choi_7.b=b;
    all_save[Currentcnt].choi_7.k=k;
    all_save[Currentcnt].choi_7.p=p;
    all_save[Currentcnt].choi_7.ans=ans;
    all_save[Currentcnt].choi_7.jud=jud;
    return ;
}