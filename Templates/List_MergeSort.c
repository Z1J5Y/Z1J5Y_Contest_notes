/*
题目描述

已有a、b两个链表，每个链表中的结点包括学号、成绩。
要求把两个链表合并，按学号升序排列。
输入

第一行，a、b两个链表元素的数量N、M,用空格隔开。
接下来N行是a的数据 然后M行是b的数据 每行数据由学号和成绩两部分组成
输出

按照学号升序排列的数据
样例输入

2 3
5 100
6 89
3 82
4 95
2 10

样例输出

2 10
3 82
4 95
5 100
6 89
*/
#include<stdio.h>
#include<stdlib.h>

struct score
{
    int sc;
    int num;
    struct score *p;
};
typedef struct score Score;

Score *InputData(Score *,int);
Score *LinkLinkedList(Score *,Score *);
void OutputData(Score*);

int main()
{
    Score *head1=NULL;
    head1=calloc(1,sizeof(Score));
    int fir;
    scanf("%d",&fir);
    head1=InputData(head1,fir);
    OutputData(head1);
    free(head1);
    return 0;
}

Score *InputData(Score *head,int a)
{
    int sc,num;
    for(int i=0;i<a;i++)
    {
        scanf("%d %d",&num,&sc);
        Score *a=calloc(1,sizeof(Score));
        a->num=num;
        a->sc=sc;
        a->p=head->p;
        head->p=a;
    }
    return head;
}
Score *LinkLinkedList(Score *head1,Score *head2)
{
    Score *medium=head1;
    for(;head1->p!=NULL;head1=head1->p);
    head1->p=head2->p;
    return medium;
}
void OutputData(Score* head)
{
	for(Score *current=head->p;current!=NULL;current=current->p)
	{
		printf("%d %d\n",current->num,current->sc);
	}
}