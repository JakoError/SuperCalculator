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

//������������
//	1:�߾��ȼӷ�
//	2:����������
//	3:���Ǻ�������
//	4:���Լ������С������
//	5:��˹��Ԫ��
//void Input_Matrix();
//void Gauss();
//	6:��������
//	7:�η�����
//	8:��������
//	9:�����¼���ļ�
//	10:����ļ��е���ʷ��¼
//	11:����ļ��е�������ʷ��¼

int main (){

    int save_cnt = 0 ;
    while (1){
        printf("-------------------------------------------------------\n");
        printf("\t\t��ã���ӭʹ�ø߼���������\n");
        printf("-------------------------------------------------------\n");
    	puts (""); 
	    printf("***************************************************\n");
        printf ("1:�߾��ȼӷ�\n");
        printf ("2:����������\n");
        printf ("3:���Ǻ�������\n");
        printf ("4:���Լ������С������\n");
        printf ("5:��˹��Ԫ��\n");
        printf ("6:��������\n");
        printf ("7:�η�����\n");//a^b % p
        printf ("8:��������\n");
		printf ("9:�����¼���ļ�\n");
        printf ("10:�����¼\n");
		printf ("11:ɾ���ļ�\n");
        printf ("12:�˳�ϵͳ(��ȷ����¼�ѱ���)\n");
		printf ("����:�����沢ֱ���˳�\n"); 
		printf("***************************************************\n");
		printf("��������ѡ��(��ɺ�س�):     ");
		
		int choice ;
		scanf ("%d",&choice);
		getchar(); 
		switch ( choice ) {
			case 1:
                if (!enter_to_high_accuracy())
                    printf ("\n�������벻�Ϸ��������¿�ʼѡ�� \n");
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
					printf ("�� %-3d �α���ɹ�\n",save_cnt);
				else printf ("����ʧ��");
				break;
			case 10:
				if (! print_history () )
				    printf ("δ���棡�뱣���鿴���������¿�ʼѡ��");
				break;
			case 11:
			    del_history();
				break;
			case 12:
                printf ("���Ѿ��˳��߼����������ڴ�������һ��ʹ�ã�");
				return 0;
			default:
				printf ("���Ѿ��˳��߼����������ڴ�������һ��ʹ�ã�");
				return 0; 
		}
		printf ("\n");
		system ("pause");
		system ("cls");
    }
    return 0;
}