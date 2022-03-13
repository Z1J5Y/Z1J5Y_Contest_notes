//链表实现链队
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct queue
{
    Node *rear,*front;
}Queue;

void InitQueue(Queue *);
void enQueue(Queue *,int );
void deQueue(Queue *,int *);
void DestoryQueue(Queue *);


int main()
{
    Queue a;
    int e;
    InitQueue(&a);
    for(int i=0;i<6;++i)
    {
        enQueue(&a,i);
    }
    for(int i=0;i<4;++i)
    {
        deQueue(&a,&e);
        printf("%d ",e);
    }

    DestoryQueue(&a);
    
    return 0;

}

void InitQueue(Queue *a)
{
    (*a).front=(*a).rear=calloc(1,sizeof(Node));
    return;
}

void enQueue(Queue *a,int b)
{
    (*a).rear->next=calloc(1,sizeof(Node));
    (*a).rear=(*a).rear->next;
    (*a).rear->data=b;
    return;
}

void deQueue(Queue *a,int *b)
{
    Node *t;
    *b=(*a).front->next->data;
    t=(*a).front->next;
    (*a).front->next=(*a).front->next->next;
    free(t);
}

void DestoryQueue(Queue *a)
{
    Node *t=(*a).front;
    while((*a).front)
    {
        t=(*a).front->next;
        free((*a).front);
        (*a).front=t;
    }
    (*a).rear=(*a).front;
}