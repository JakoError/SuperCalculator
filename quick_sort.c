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
    printf("\n请输入需排列的数字的个数：\n");
    scanf("%d",&all_save[Currentcnt].choi_6.n);
    printf("请输入需排列的数字：");

    for(i=0;i<all_save[Currentcnt].choi_6.n;++i){
        scanf("%d",&all_save[Currentcnt].choi_6.a[i]);
        all_save[Currentcnt].choi_6.ans[i] = all_save[Currentcnt].choi_6.a[i] ;
    }
//				 puts("1");
    q_sort_stack(Currentcnt);
    printf("排列后的顺序为：");
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
    push(left);//压入最左边的下标
    push(right);//压入最后边的下标
    while(!is_empty())//判断栈里是否还有数，如果没有，则不进行下面的循环
    {
        right=pop();
        left=pop();//删除该数据

        int index = partition(left, right);//调用 int partition(int left, int right)；
        if (index - 1 > left)
        {
            push(left);
            push(index - 1);//压入左边的数据
        }
        if (index + 1 < right)
        {
            push(index + 1);
            push(right);//压入右边的数据
        }
    }
}
