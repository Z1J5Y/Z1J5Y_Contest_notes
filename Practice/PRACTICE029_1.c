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

void InitQueue (Node **,Queue *);
void enQueue(Node **,Queue *,int );
void deQueue(Queue *,int *);


int main()
{
    int t;
    Node *NodeList;
    Queue a;
    InitQueue(&NodeList,&a);
    enQueue(&NodeList,&a,12);
    enQueue(&NodeList,&a,13);
    enQueue(&NodeList,&a,14);
    enQueue(&NodeList,&a,15);
    for(int i=0;i<4;i++)
    {
        deQueue(&a,&t);
        printf("%d ",t);
    }

    return 0;
}

void InitQueue (Node **a,Queue *b)
{
    (*a)=calloc(1,sizeof(Node));
    (*a)->data=0;
    (*a)->next=NULL;
    (*b).rear=(*b).front=*a;
}

void enQueue(Node **a,Queue *b,int c)
{
    Node *t=*a;
    for(;t->next!=NULL;t=t->next);
    t->next=calloc(1,sizeof(Node));
    t->next->data=c;
    t->next->next=NULL;
    (*b).rear=t->next;

}

void deQueue(Queue *b,int *c)
{
    *c=(*b).front->data;
    (*b).front=(*b).front->next;
}