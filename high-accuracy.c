//
// Created by violinwang on 2021/1/1.
//

#include "Define_first.h"
#include "high-accuracy.h"

extern Recording all_save[MAX_REC_NUM];
extern int Currentcnt;

bool enter_to_high_accuracy(){
    char temp_formula [MAX_FORMU_LEN];
    printf ("\n请输入合法表达式： \n");
    int temp_len = read_line (temp_formula,MAX_FORMU_LEN);
    if (! add_calculate(temp_formula,temp_len) )
        return false;
    return true;
}

bool add_calculate(char str[],int len) {
    reverse (str,len);
    int m = fnd_formula_split (str,len);
    if (m==-1)  return false;
    int len1 = m ;
    char * p1 = (char *) calloc (m+1,sizeof (char));

    int len2 = len-m-1 ;
    char * p2 = (char *) calloc ( len-m,sizeof (char));

    formula_split (&p1,str,len1);
    formula_split (&p2,str+m+1,len2);

    int * ans = calloc ( Max(len1,len2)+1,sizeof (int));
    int ans_len;
    if (len1>len2)
        ans_len= get_cal_ans ( p1, p2, len1,len2,ans) ;
    else
        ans_len= get_cal_ans ( p2, p1, len2,len1,ans) ;
    int i;
    reverse (str,len);
    for (i=0;i<len;++i)
        printf ("%c",str[i]);
    putchar ('=');
    for (i=ans_len-1;i>=0;--i)
        printf ("%d",ans[i]);
    puts("");puts("");
    save_to_Recording_1(str,ans,ans_len);
    return true;
}


int fnd_formula_split (char str[],int len) {
    int i = 0;
    for (; i < len-1; ++i)
        if (str[i] == '+')
            return i;
    return -1;
}

void formula_split (char **p ,char* str,int len){
    strncpy (*p,str,sizeof (char)* len);
    *(*p+len)='\0';
    return ;
}

int get_cal_ans (char *p1,char *p2,int len1,int len2,int *ans){
    int i=0;
    for (i=0;i<=len1;++i){
        ans[i] = 0;
    }

    for (i=0;i<len2;++i){
        int a = *(p1+i) - '0';
        int b = *(p2+i) - '0';
        int temp_ans = ans[i] + a + b;
        *(ans+i) = temp_ans%10;
        *(ans+i+1) += temp_ans/10;
    }

    for (;i<len1;++i){
        int a = *(p1+i) - '0';
        int temp_ans = (*(ans+i)) + a;
        *(ans+i) = temp_ans%10;
        *(ans+i+1) += temp_ans/10;
    }

    if (ans[len1]==0) return len1;
    else return len1+1 ;

}
void reverse (char str[],int len){
    char * str_new = calloc(len+1,sizeof (char));
    strcpy (str_new,str);
    int i=0;
    while (i<len)
        str[i] = str_new[len-i-1],++i;
    free(str_new);
    return ;
}
void save_to_Recording_1(char str[],int * ans,int ans_len){
    int i;
    strcpy ( all_save[++Currentcnt].choi_1.formula , str);
    for (i=0;i<ans_len;++i)
        all_save[Currentcnt].choi_1.ans[i] = (int)ans[i];
    all_save[Currentcnt].choi_1.ans_len = ans_len;
    all_save[Currentcnt].choice = 1;
}

int read_line (char str[],int n){
    int ch,i=0;
    while ( ( ch=getchar () ) != '\n')
        if (i<n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int Max (int x,int y){
    return x>y?x:y;
}