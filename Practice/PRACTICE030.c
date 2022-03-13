//顺序表实现循环队列
#include<stdio.h>
#include<stdlib.h>
#define INITSIZE 5

typedef struct queue
{
    int *q;
    int rear,front;
}Queue;

void InitQueue(Queue *);
int enQueue(Queue *,int );
int deQueue(Queue *,int *);
int main()
{
    Queue a;
    int e;
    InitQueue(&a);
    for(int i=0;i<4;++i)
    {
        if(!enQueue(&a,i))
        {
            printf("ERROR,QUEUE IS FULL");
            return 1;
        }
    }
    for(int i=0;i<4;++i)
    {
        if(!deQueue(&a,&e))
        {
            printf("ERROR,QUEUE IS EMPTY");
            return 1;
        }
        printf("%d ",e);
    }

    return 0;
}

void InitQueue(Queue *a)
{
    (*a).q=(int *)calloc(INITSIZE,sizeof(int));
    (*a).rear=(*a).front=0;
}

int enQueue(Queue *a,int b)
{
    if((*a).front==((*a).rear+1)%INITSIZE) return 0;
    (*a).rear=((*a).rear+1)%INITSIZE;
    *((*a).q+(*a).rear)=b;
    return 1;
}
int deQueue(Queue *a,int *b)
{
    if((*a).front==(*a).rear) return 0;
    (*a).front=((*a).front+1)%INITSIZE;
    *b=*((*a).q+(*a).front);
    return 1;
}