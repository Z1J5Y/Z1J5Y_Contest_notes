#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
#define AddSize 10

typedef struct Stack
{
    int *base,*top,num;
}stack;

void InitStack(stack *a);
void DestroyStack(stack *a);
void ClearStack(stack *a);
void Push(stack *a,int b);
int Pop(stack *a,int *b);

int main()
{
    int e;
    stack a;
    InitStack(&a);
    for(int i=0;i<5;++i)
    {
        Push(&a,i);
    }
    for(int i=0;i<5;++i)
    {
        if(!Pop(&a,&e)) return 1;
        printf("%d ",e);
    }
    DestroyStack(&a);
    return 0;
}
void InitStack(stack *a)
{
    (*a).base=malloc(InitSize*sizeof(int));
    (*a).top=a->base;
    (*a).num=InitSize;
}
void DestroyStack(stack *a)
{
    free((*a).base);
    (*a).base=NULL;
    (*a).top=(*a).base;
    (*a).num=0;
}
void ClearStack(stack *a)
{
    (*a).top=(*a).base;
    (*a).num=0;
}
void Push(stack *a,int b)
{
    if((*a).top-(*a).base>=(*a).num)
    {
        (*a).base=realloc((*a).base,AddSize*sizeof(int));
        (*a).top=(*a).base+(*a).num;
    }
    *(*a).top++=b;
}
int Pop(stack *a,int *b)
{
    if((*a).base==(*a).top) return 0;
    (*b)=*(--(*a).top);
    return 1;
}