#include<iostream>
#include<string>
//哈夫曼树
struct ElemType
{
    char data;
    int weight;
};
struct BTree
{
    ElemType data;
    BTree *rchild,*lchild,*parent;
};
struct Queue
{
    BTree alphabet[27];
    int top;
};

void CreatQueue(Queue&,char*);
void EnQueue(Queue&,BTree*);
int DeQueue(Queue&,BTree*&);
void Sort(Queue&);
void Sort(Queue&,int);
void CreatHFTree(BTree*&,Queue&);
void DestoryTree(BTree*&);

int main()
{
    char a[25]{0};
    scanf("%s",a);
    Queue Q{0};
    CreatQueue(Q,a);

    BTree *ex=NULL;
    CreatHFTree(ex,Q);


    return 0;
}

void Sort(Queue &a,int flag)
{
    ElemType temp;
    int i,j;
    for(i=a.top;a.alphabet[i].data.weight;i++)
    {
        if(a.alphabet[a.top].data.weight>a.alphabet[i].data.weight&&
        a.alphabet[a.top].data.weight<=a.alphabet[i+1].data.weight)
        {
            for(j=25;j>i;--j)
                a.alphabet[j+1]=a.alphabet[j];
            a.alphabet[j+1]=a.alphabet[a.top++];
            break;
        }
    }
    if(a.alphabet[a.top].data.weight>a.alphabet[i-1].data.weight)
        a.alphabet[i]=a.alphabet[a.top++];
}

void Sort(Queue &a)
{
    ElemType temp;
    int i,j;

    for(i=0;a.alphabet[i].data.data!='Z';++i)
        if(!a.alphabet[i].data.weight)
        {
            for(j=i;a.alphabet[j].data.data!='Z';++j)
                a.alphabet[j]=a.alphabet[j+1];
            --i;
        }
    for(i=0;a.alphabet[i].data.weight;++i)
    {
        int t=i;
        for(j=i+1;a.alphabet[j].data.weight;++j)
            if(a.alphabet[t].data.weight>a.alphabet[j].data.weight)
                t=j;
        if(t!=i)
        {
            temp=a.alphabet[i].data;
            a.alphabet[i].data=a.alphabet[t].data;
            a.alphabet[t].data=temp;
        }
    }
}

void CreatQueue(Queue &a,char *b)
{
    int i,j;
    for(i=0;i<26;++i) a.alphabet[i].data.data='A'+i;
    for(i=0;i<26;++i)
        for(j=0;b[j];++j)
            if(a.alphabet[i].data.data==b[j])
                ++a.alphabet[i].data.weight;
    Sort(a);
}

void EnQueue(Queue &a,BTree *b)
{
    a.alphabet[--a.top]=*b;
    Sort(a,0);
}

int DeQueue(Queue &a,BTree *&b)
{
    if(a.alphabet[a.top].data.weight==0) return 0;
    *b=a.alphabet[a.top++];
    return 1;
}

void CreatHFTree(BTree *&a,Queue &b)
{
    BTree *tnode=NULL;
    BTree *tdata1,*tdata2;
    tdata1=new BTree();
    tdata2=new BTree();
    while(DeQueue(b,tdata1)&&DeQueue(b,tdata2))
    {
        tnode=new BTree();
        
        tnode->data.weight=tdata1->data.weight+tdata2->data.weight;
        tnode->lchild=tdata1;
        tnode->rchild=tdata2;
        tnode->parent=NULL;
        tdata1->parent=tdata2->parent=tnode;
        EnQueue(b,tnode);
        tdata1=new BTree();
        tdata2=new BTree();
    }
    delete tdata1;
    delete tdata2;
    a=tnode;
}

void DestoryTree(BTree*&a)
{
    if(a)
    {
        DestoryTree(a->lchild);
        DestoryTree(a->rchild);
        free(a);
    }
}