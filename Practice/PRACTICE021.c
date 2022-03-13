//链栈
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;
typedef struct stack
{
    Node *data;
    Node *base,*top;
}Stack;

void InitStack(Stack *);
void Push(Stack *,int );
int Pop(Stack *,int *);

int main()
{
    Stack a;
    InitStack(&a);
    int e;
    for(int i=0;i<5;++i)
    {
        Push(&a,i);
    }
    for(int i=0;i<5;++i)
    {
        if(!(Pop(&a,&e))) return 1;
        printf("%d ",e);
    }
    return 0;
}

void InitStack(Stack *a)
{
    (*a).data=(Node *)calloc(1,sizeof(Node));
    (*a).data->data=0;
    (*a).data->next=NULL;
    (*a).base=(*a).top=(*a).data;
}

void Push(Stack *a,int b)
{
    Node *t=(*a).top;
    t->next=(Node *)calloc(1,sizeof(Node));
    t->next->data=b;
    (*a).top=t->next;
}

int Pop(Stack *a,int *b)
{
    if((*a).base==(*a).top) return 0;
    Node *t=(*a).base;
    *b=(*a).top->data;
    while(t->next!=(*a).top) t=t->next;
    (*a).top=t;
    free(t->next);
    return 1;
}
