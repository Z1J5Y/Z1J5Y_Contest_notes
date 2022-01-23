#include<stdio.h>
#include<stdlib.h>

typedef char ElemType;

typedef struct btree
{
    ElemType data;
    struct btree *rchild,*lchild;
    int rtag,ltag;
}BTree;

BTree *pre;

void CreatTree(BTree**);
void ThreadBTree(BTree**);
BTree *CreatThreadBTree(BTree**);
void TravseThreadBTree(BTree**);


int main()
{
    BTree *ex=NULL;
    CreatTree(&ex);
    ex=CreatThreadBTree(&ex);
    TravseThreadBTree(&ex);


    return 0;
}

void CreatTree(BTree **a)
{
    (*a)=(BTree *)calloc(1,sizeof(BTree));
    (*a)->data='A';
    (*a)->ltag=0;
    (*a)->rtag=0;
    (*a)->lchild=(BTree *)calloc(1,sizeof(BTree));
    (*a)->lchild->data='B';
    (*a)->lchild->ltag=1;
    (*a)->lchild->rtag=0;
    (*a)->lchild->rchild=(BTree *)calloc(1,sizeof(BTree));
    (*a)->lchild->rchild->data='C';
    (*a)->lchild->rchild->ltag=1;
    (*a)->lchild->rchild->rtag=1;
    (*a)->rchild=(BTree *)calloc(1,sizeof(BTree));
    (*a)->rchild->data='D';
    (*a)->rchild->ltag=1;
    (*a)->rchild->rtag=0;
    (*a)->rchild->rchild=(BTree *)calloc(1,sizeof(BTree));
    (*a)->rchild->rchild->data='E';
    (*a)->rchild->rchild->rtag=1;
    (*a)->rchild->rchild->ltag=0;
    (*a)->rchild->rchild->lchild=(BTree *)calloc(1,sizeof(BTree));
    (*a)->rchild->rchild->lchild->data='F';
    (*a)->rchild->rchild->lchild->ltag=1;
    (*a)->rchild->rchild->lchild->rtag=1;
}

void Thread(BTree**a)
{
    if(*a)
    {
        Thread(&(*a)->lchild);
        if((*a)->ltag)
            (*a)->lchild=pre;
        if(pre->rtag)
            pre->rchild=*a;
        pre=*a;
        Thread(&(*a)->rchild);
    }
}
BTree *CreatThreadBTree(BTree**a)
{
    BTree *head=(BTree*)calloc(1,sizeof(BTree));

    pre=head;
    head->ltag=0;
    head->rtag=1;
    head->lchild=*a;
    Thread(&(*a));
    head->rchild=pre;
    pre->rchild=head;

    return head;
}

void InorderTravseThreadBTree(BTree**a)
{
    BTree *t=(*a)->lchild;
    while(t!=(*a))
    {
        while(!(t->ltag))
            t=t->lchild;
        printf("%c",t->data);
        while(t->rtag&&t->rchild!=(*a))
        {
            t=t->rchild;
            printf("%c",t->data);
        }
        t=t->rchild;
    }
}