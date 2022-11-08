#include <stdio.h>
#include <stdlib.h>
#include "Define_first.h"
#include "matrix.h"
#include "high-accuracy.h"
#include "Greatest Common Divisor & Least Common Multiple.h"
#include "Gauss-Jordan Elimination.h"
#include "quick_sort.h"
#include "complex math.h"
#include "quick_pow.h"
#include "tri-math functions.h"
#include "file-operate functions.h"

Recording all_save[MAX_REC_NUM];
int Currentcnt = 0;
extern Recording all_save[MAX_REC_NUM];
extern int Currentcnt;

//函数声明部分
//	1:高精度加法
//	2:矩阵混合运算
//	3:三角函数运算
//	4:最大公约数与最小公倍数
//	5:高斯消元法
//void Input_Matrix();
//void Gauss();
//	6:整理序列
//	7:次方运算
//	8:复数运算
//	9:保存记录至文件
//	10:输出文件中的历史记录
//	11:清空文件中的所有历史记录

int main (){

    int save_cnt = 0 ;
    while (1){
        printf("-------------------------------------------------------\n");
        printf("\t\t你好！欢迎使用高级计算器！\n");
        printf("-------------------------------------------------------\n");
    	puts (""); 
	    printf("***************************************************\n");
        printf ("1:高精度加法\n");
        printf ("2:矩阵混合运算\n");
        printf ("3:三角函数运算\n");
        printf ("4:最大公约数与最小公倍数\n");
        printf ("5:高斯消元法\n");
        printf ("6:整理序列\n");
        printf ("7:次方运算\n");//a^b % p
        printf ("8:复数运算\n");
		printf ("9:保存记录至文件\n");
        printf ("10:输出记录\n");
		printf ("11:删除文件\n");
        printf ("12:退出系统(请确保记录已保存)\n");
		printf ("其他:不保存并直接退出\n"); 
		printf("***************************************************\n");
		printf("输入您的选择(完成后回车):     ");
		
		int choice ;
		scanf ("%d",&choice);
		getchar(); 
		switch ( choice ) {
			case 1:
                if (!enter_to_high_accuracy())
                    printf ("\n您的输入不合法！请重新开始选择！ \n");
				break;
            case 2:
                matrixMain();
                break;
			case 3:
                tri_math_cal ();
				break;
			case 4:
			    GCD_LCM();
				break;
			case 5:
    			Input_Matrix();
    			break;
			case 6:
				quick_sort ();
				break;
			case 7:
			    quick_pow();
				break;
			case 8:
                Complex_cal();
				break;
			case 9:
				if ( save_to_file(&save_cnt) )
					printf ("第 %-3d 次保存成功\n",save_cnt);
				else printf ("保存失败");
				break;
			case 10:
				if (! print_history () )
				    printf ("未保存！请保存后查看！现请重新开始选择！");
				break;
			case 11:
			    del_history();
				break;
			case 12:
                printf ("您已经退出高级计算器！期待您的下一次使用！");
				return 0;
			default:
				printf ("您已经退出高级计算器！期待您的下一次使用！");
				return 0; 
		}
		printf ("\n");
		system ("pause");
		system ("cls");
    }
    return 0;
}