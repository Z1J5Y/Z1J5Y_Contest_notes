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
        struct
        {
            struct list *hp,*tp;
        }ptr;
    }next;
}List;

void DisplayList(List *);
int ListDepth(List *);
List *CopyList(List *);

int main()
{
    List *a=NULL;//无头结点的广义表
    a=calloc(1,sizeof(List));
    a->tag=1;
    a->next.ptr.hp=calloc(1,sizeof(List));
    a->next.ptr.hp->tag=0;
    a->next.ptr.hp->next.data.a=100;
    a->next.ptr.tp=calloc(1,sizeof(List));
    a->next.ptr.tp->tag=1;
    a->next.ptr.tp->next.ptr.hp=calloc(1,sizeof(List));
    a->next.ptr.tp->next.ptr.hp->tag=1;
    a->next.ptr.tp->next.ptr.hp->next.ptr.hp=calloc(1,sizeof(List));
    a->next.ptr.tp->next.ptr.hp->next.ptr.hp->tag=0;
    a->next.ptr.tp->next.ptr.hp->next.ptr.hp->next.data.a=200;
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp=calloc(1,sizeof(List));
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp->tag=1;
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp->next.ptr.hp=calloc(1,sizeof(List));
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp->next.ptr.hp->tag=0;
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp->next.ptr.hp->next.data.a=300;
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp->next.ptr.tp=calloc(1,sizeof(List));
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp->next.ptr.tp->tag=1;
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp->next.ptr.tp->next.ptr.hp=calloc(1,sizeof(List));
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp->next.ptr.tp->next.ptr.hp->tag=0;
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp->next.ptr.tp->next.ptr.hp->next.data.a=400;
    a->next.ptr.tp->next.ptr.hp->next.ptr.tp->next.ptr.tp->next.ptr.tp=NULL;
    a->next.ptr.tp->next.ptr.tp=NULL;

    int depth=ListDepth(a);
    List *b=CopyList(a);
    DisplayList(b);

    return 0;
}

void DisplayList(List *a)
{
    if(!a) return;
    if(!a->tag)
    {
        printf("%d ",a->next.data);
        return;
    }
    for(;a;a=a->next.ptr.tp)
    {
        DisplayList(a->next.ptr.hp);
    }
}

int ListDepth(List *a)
{
    int depth=0,mdepth=0;
    List *temp=a;
    if(!a) return 1;
    if(!a->tag) return 0;
    for(;temp;temp=temp->next.ptr.tp)
    {
        depth=ListDepth(temp->next.ptr.hp);
        if(depth>mdepth) mdepth=depth;
    }
    return mdepth+1;
}
List *CopyList(List *a)
{
    List *t=NULL;

    if(!a) return t;

    t=calloc(1,sizeof(List));

    if(a->tag==0)
    {
        t->tag=a->tag;
        t->next.data=a->next.data;
    }
    else if(a->tag==1)
    {
        t->tag=a->tag;
        t->next.ptr.hp=CopyList(a->next.ptr.hp);
        t->next.ptr.tp=CopyList(a->next.ptr.tp);
    }

    return t;
}