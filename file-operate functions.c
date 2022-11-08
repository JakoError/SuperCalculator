//
// Created by violinwang on 2021/1/5.
//

#include "Define_first.h"
#include "file-operate functions.h"

extern Recording all_save[MAX_REC_NUM];
extern int Currentcnt;
char file_name[MAX_FILE_NAME_LEN];
char user_name[MAX_USER_NAME_LEN];

bool save_to_file(int * save_cnt){

    (*save_cnt) ++ ;
    if(*save_cnt ==1){
        printf ("请输入创建的文件名:\n--> ");
        int len1 = read_line(file_name,MAX_FILE_NAME_LEN+1);
        printf ("请输入您的用户名:\n--> ");
        int len2 = read_line(user_name,MAX_USER_NAME_LEN+1);
        printf("-------------------------------------------------------\n");
        printf ("\t创建成功！\n");
        printf("-------------------------------------------------------\n");
        strcat(file_name,".txt");
        FILE * fp;
        //写数据，若指定的文件不存在则创建它，如果存在则先删除它再重建一个新文件
        if ((fp = fopen (file_name, "w") ) == NULL){
            return false;
        }
        fprintf (fp,"\n你好！%s！\n\n",user_name);
        write_to_file(fp);
        fclose (fp);
        return true;
    }

    FILE *fp;
    if ((fp = fopen (file_name,"a")) == NULL)
        return false;

    write_to_file(fp);
    fclose (fp);
    return true;
}


void write_to_file(FILE * fp){
    int i=1,j,k;
    for (;i<=Currentcnt;++i){
        int choice = all_save[i].choice;
        switch (choice){
            case 0:
                fprintf (fp,"%s=%d\n",all_save[i].choi_0.formula,all_save[i].choi_0.ans);
                break;
            case 1:
                fprintf (fp,"%s=",all_save[i].choi_1.formula);
                j=all_save[i].choi_1.ans_len-1;
                for (;j>=0;--j)
                    fprintf (fp,"%d",all_save[i].choi_1.ans[j]);
                fprintf (fp,"\n");
                break;
            case 3:
                fprintf(fp,"%lf的正弦函数的值为%lf\n",all_save[i].choi_3.a,all_save[i].choi_3.b);
                break;
            case 4:
                fprintf (fp,"%d 和 %d的最大公约数为%d 最小公倍数为%d\n",all_save[i].choi_4.a,all_save[i].choi_4.b,all_save[i].choi_4.ans1,all_save[i].choi_4.ans2);
                break;
            case 5:
                fprintf (fp,"您输入的矩阵为： ");
                for (j=0;j<all_save[i].choi_5.NUM;++j){
                    for (k=0;k<all_save[i].choi_5.NUM;++k)
                        fprintf (fp,"%.2lf ",all_save[i].choi_5.A[j][k]);
                    fprintf (fp,"\n");
                }
                fprintf(fp,"结果X:\n");
                for(j=0; j<all_save[i].choi_5.NUM; j++)
                    fprintf(fp,"x%d=%.2lf\n",j+1,all_save[i].choi_5.X[j]);
                break;
            case 6:
                fprintf (fp,"原序列为：   ");
                for (j=0;j<all_save[i].choi_6.n;++j)
                    fprintf (fp,"%d ",all_save[i].choi_6.a[j]);
                fprintf(fp,"从小到大排列为： ");
                for (j=0;j<=all_save[i].choi_6.n;++j)
                    fprintf (fp,"%d ",all_save[i].choi_6.ans[j]);
                fprintf (fp,"\n");
                break;
            case 7:
                if (all_save[i].choi_7.jud == 0)
                    fprintf (fp,"%d的%d次方对%d取余的答案为:1/%ld\n", all_save[i].choi_7.b, all_save[i].choi_7.k , all_save[i].choi_7.p , all_save[i].choi_7.ans);
                else
                    fprintf (fp,"%d的%d次方对%d取余的答案为:%ld\n", all_save[i].choi_7.b, all_save[i].choi_7.k , all_save[i].choi_7.p , all_save[i].choi_7.ans);
            case 8:
                if(all_save[i].choi_8.A.b > 0)
                    fprintf(fp,"\n(%.2lf+%.2lfi) %c", all_save[i].choi_8.A.a, all_save[i].choi_8.A.b, all_save[i].choi_8.tmp);
                else
                    fprintf(fp,"\n(%.2lf%.2lfi) %c", all_save[i].choi_8.A.a, all_save[i].choi_8.A.b, all_save[i].choi_8.tmp);
                if(all_save[i].choi_8.B.b > 0)
                    fprintf(fp," (%.2lf+%.2lfi) =", all_save[i].choi_8.B.a, all_save[i].choi_8.B.b);
                else
                    fprintf(fp," (%.2lf%.2lfi) =", all_save[i].choi_8.B.a, all_save[i].choi_8.B.b);
                if(all_save[i].choi_8.answer.b > 0)
                    fprintf(fp,"%.2lf+%.2lfi", all_save[i].choi_8.answer.a, all_save[i].choi_8.answer.b);
                else
                    fprintf(fp,"%.2lf%.2lfi", all_save[i].choi_8.answer.a, all_save[i].choi_8.answer.b);

        }
    }

    Currentcnt = 0 ;
    return ;
}

bool print_history(){
    FILE * fp;
    fp = fopen (file_name,"r") ;
    if (file_name == NULL )
        return false;
    int ch;
    while ( (ch = getc(fp)) !=EOF)
        putchar (ch);
    fclose (fp);
    return true;
}

void del_history(){
    int temp_choice;
    printf ("是否删除历史记录？\n");
    printf ("1: 是\t0: 否");
    printf ("请选择：    ");
    scanf ("%d",&temp_choice);
    switch (temp_choice) {
        case 0:
            break;
        case 1:
            if ( !file_clear() )
                printf ("未保存！请保存后查看！现请重新开始选择！\n");
            break;
        default:
            printf ("无效输入！请重新开始选择！\n");
    }
    return ;
}

bool file_clear(){
    if (file_name == NULL)
        return false;
    remove(file_name);
    return true;
}