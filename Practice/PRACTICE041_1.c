#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int a;
}elemtype;

typedef struct list
{
    int tag;
    union
    {
        elemtype data;
        struct list *hp,*tp
    }*next;
}List;


int main()
{
    List *a;
    a=calloc(1,sizeof(List));
    a->tag=1;
    a->next->hp=calloc(1,sizeof(List));
    a->next->hp->tag=0;
    a->next->hp->next->data.a=100;
    a->next->tp=calloc(1,sizeof(List));
    a->next->tp->tag=1;
    a->next->tp->next->hp=calloc(1,sizeof(List));
    a->next->tp->next->hp->tag=0;
    a->next->tp->next->hp->next->data.a=2;
    return 0;
}