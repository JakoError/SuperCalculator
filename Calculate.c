//
// Created by violinwang on 2021/1/1.
//

#include "Define_first.h"
#include "Calculate.h"

char s[MAX_FORMU_LEN];

extern Recording all_save[MAX_REC_NUM];
extern int Currentcnt;

bool _calculate(){
    printf ("----请输入一行仅包含非负整数加减乘的算式----\n");
    scanf ("%s",s);
    if (!_jud()) return false;
    all_save[++Currentcnt].choice = 0;
    strcpy(all_save[Currentcnt].choi_0.formula,s);
    int len = strlen (s);
    s[len] = '+';
    s[len+1] = '\0';
    all_save[Currentcnt].choi_0.ans = cal(0,strlen(s)-1);
    printf ("%d\n",all_save[Currentcnt].choi_0.ans);
    return true;
}

bool _jud(){
    int i;
    for (i=0;i<strlen(s);++i)
        if (s[i]!='+' && s[i]!='-' && s[i]!='*' && (s[i]<'0'||s[i]>'9') )
            return false;
    return true;
}

int cal(int l,int r){//无括号的混合运算
    //l:数字开始 r:数字结尾
    int ans=0;
    int jud_or = 1;
    do{
        ans += jud_or * ( num_or_multiply(&l,r) );
        if (s[l] == '+') jud_or=1;
        else if (s[l] == '-') jud_or=-1;
        //printf ("%d %d\n",l,ans);
        l++;
    }while (l<=r);
    return ans;
}


//从当前数字开始是 乘法 还是 数字
//乘法 返回结果
//数字

int num_or_multiply(int *l,int r){
    int i=*l;
    for (*l;(*l)<=r;++(*l)){
        if (s[*l] == '+' || s[*l] == '-')
            return get_num_left(*l,i);
        if (s[*l] == '*' ){
            while (s[*l]!='+' && s[*l]!='-' &&(*l)<r)
                (*l)++;
            return multip(i-1,*l);
        }
    }
}


int multip (int l,int r){//左边的+\-位置 右边的+\-位置
    int i;
    int num_left,num_right;
    for (i=l+1;i<r;++i){
        if (s[i] == '*'){
            num_left = get_num_left(i,l+1);
            break;
        }
    }
    for (i;i<r;++i){
        if (s[i]=='*'){
            num_right = get_num_right(i,i,r);
            num_left *= num_right;
        }
    }
    return num_left;
}

int get_num_left (int pos,int l){
    //123+
    //pos
    //l包含在计算中
    int ans = 0;
    int wei = 0;
    while (pos>l){
        --pos;
        if (s[pos] <'0' ||  s[pos]>'9') break;
        ans += ksm(wei) * ( s[pos] - '0') ;
        wei ++ ;
    }
    return ans;
}


int get_num_right (int pos,int l,int r){
    //-123
    //r包含在计算内
    while (pos<r){
        ++pos;
        if (s[pos] < '0'|| s[pos]>'9') break;
    }
    return get_num_left(pos,l+1);
}


int ksm (int wei){
    //10^wei
    if (!wei) return 1;
    int ans = 1;
    int bse = 10;
    while (wei){
        if (wei&1) ans*=bse;
        wei>>=1;
        bse *= bse;
    }
    return ans;
}