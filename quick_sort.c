//
// Created by violinwang on 2021/1/5.
//

#include "Define_first.h"
#include "quick_sort.h"

extern Recording all_save[MAX_REC_NUM];

int top=0;
int contents[STACK_SIZE];
extern Currentcnt;

void quick_sort (){
    int i,j;
    all_save[++Currentcnt].choice = 6;
    printf("\n�����������е����ֵĸ�����\n");
    scanf("%d",&all_save[Currentcnt].choi_6.n);
    printf("�����������е����֣�");

    for(i=0;i<all_save[Currentcnt].choi_6.n;++i){
        scanf("%d",&all_save[Currentcnt].choi_6.a[i]);
        all_save[Currentcnt].choi_6.ans[i] = all_save[Currentcnt].choi_6.a[i] ;
    }
//				 puts("1");
    q_sort_stack(Currentcnt);
    printf("���к��˳��Ϊ��");
    for(j=0;j<all_save[Currentcnt].choi_6.n;++j)
        printf("%d\t",all_save[Currentcnt].choi_6.ans[j]);
    printf ("\n");
}

void stack_underflow()
{
    exit(EXIT_FAILURE);
}
void stack_overflow()
{
    printf("Stack overflow");
    exit(EXIT_FAILURE);
}
void make_empty(void)
{
    top=0;
}
int is_empty(void)
{
    return top==0;
}
int is_full(void)
{
    return top==STACK_SIZE;
}
void push(int i)
{
    if(is_full())
        stack_overflow();
    else
        contents[top++] = i;
}
int pop(void)
{
    if(is_empty())
        stack_underflow();
    else
        return contents[--top];
}

int partition(int left, int right)
{
    int pivot = all_save[Currentcnt].choi_6.ans[left];
    while (left < right)
    {
        while (left < right && all_save[Currentcnt].choi_6.ans[right] >= pivot)
            right--;
        all_save[Currentcnt].choi_6.ans[left] = all_save[Currentcnt].choi_6.ans[right];
        while (left < right && all_save[Currentcnt].choi_6.ans[left] <= pivot)
            left++;
        all_save[Currentcnt].choi_6.ans[right] = all_save[Currentcnt].choi_6.ans[left];
    }
    all_save[Currentcnt].choi_6.ans[left] = pivot;
    return left;
}

void q_sort_stack()
{
    int left = 0;
    int right = all_save[Currentcnt].choi_6.n - 1;
    push(left);//ѹ������ߵ��±�
    push(right);//ѹ�����ߵ��±�
    while(!is_empty())//�ж�ջ���Ƿ����������û�У��򲻽��������ѭ��
    {
        right=pop();
        left=pop();//ɾ��������

        int index = partition(left, right);//���� int partition(int left, int right)��
        if (index - 1 > left)
        {
            push(left);
            push(index - 1);//ѹ����ߵ�����
        }
        if (index + 1 < right)
        {
            push(index + 1);
            push(right);//ѹ���ұߵ�����
        }
    }
}
