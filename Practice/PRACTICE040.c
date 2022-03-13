#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int x,y,value;
}ThreeTuple;

typedef struct linkedlist
{
    ThreeTuple value;
    struct linkedlist *next;
}Linkedlist;


void InitLinkedlist(Linkedlist *);
int InputValue(Linkedlist *,ThreeTuple *);


int main()
{
    int map[10][10]={ {1,1,1,1,1,1,1,1,1,1},
                    {1,0,0,1,0,0,0,1,0,1},
                    {1,0,0,1,0,0,0,1,0,1},
                    {1,0,0,0,0,1,1,0,0,1},
                    {1,0,1,1,1,0,0,0,0,1},
                    {1,0,0,0,1,0,0,0,0,1},
                    {1,0,1,0,0,0,1,0,0,1},
                    {1,0,1,1,1,0,1,1,0,1},
                    {1,1,0,0,0,0,0,0,0,1},
                    {1,1,1,1,1,1,1,1,1,1}};
    Linkedlist a;
    ThreeTuple t;

    InitLinkedlist(&a);
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<10;++j)
        {
            if(map[i][j])
            {
                t.x=i,t.y=j,t.value=map[i][j];
                InputValue(&a,&t);
            }
        }
    }

    for(Linkedlist *temp=a.next;temp->next;temp=temp->next)
    {
        printf("%d %d %d\n",temp->value.x,temp->value.y,temp->value.value);
    }

}
void InitLinkedlist(Linkedlist *a)
{
    (*a).next=NULL;
    (*a).value.x=(*a).value.y=(*a).value.value=0;
}
int InputValue(Linkedlist *a,ThreeTuple *b)
{
    Linkedlist *t=calloc(1,sizeof(Linkedlist));
    if(!t) return 0;

    t->value=(*b);
    t->next=(*a).next;
    (*a).next=t;

    return 1;
}