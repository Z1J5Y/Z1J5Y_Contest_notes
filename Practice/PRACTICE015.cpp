#include<iostream>

struct List
{
    int data;
    List *next;
};

void InitialList1(List*&);
void InitialList2(List*&);

int main()
{
    List *EX1=NULL,*EX2=NULL;
    InitialList1(EX1);
    InitialList2(EX2);
    return 0;
}

void InitialList1(List *&a)
{
    List *t=NULL;
    a=new List{};
    for(int i=0;i<10;++i)
    {
        t=new List{};
        t->data=i;
        t->next=a->next;
        a->next=t;
    }
}
void InitialList2(List *&a)
{
    a=new List{};
    List *t=NULL,*s=a;

    for(int i=0;i<10;++i)
    {
        t=new List{};
        t->data=i;
        s->next=t;
        s=t;
    }
}