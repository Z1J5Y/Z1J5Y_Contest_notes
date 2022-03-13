//二叉树的创建 销毁 元素查找
#include<stdio.h>
#include<stdlib.h>

typedef struct binarytree
{
    char data;
    struct binarytree *lchild,*rchild;
}Tree;

Tree *CreatTree(Tree *,char *);
void DestoryTree(Tree *);
void PreOrderTraverse(Tree *);
void FindNode(Tree *,char ,Tree **);

int main()
{
    char *b="A(B(D(,G)),C(E,F))";
    Tree *a=NULL;
    a=CreatTree(a,b);

    PreOrderTraverse(a);
    Tree *t=NULL;
    FindNode(a,'G',&t);

    printf("%c ",(*t).data);

    DestoryTree(a);

    return 0;
}

Tree *CreatTree(Tree *a,char *b)
{
    int i=0,sign=0,top=0;//sigb==0为左孩子节点,1为右孩子节点
    Tree *st[10]={NULL};
    Tree *t=NULL;
    while(b[i])
    {
        switch (b[i])
        {
        case '(':
            st[top++]=t;
            sign=0;
            break;

        case ',':
            sign=1;
            break;

        case ')':
            --top;
            break;

        default:
            t=calloc(1,sizeof(Tree));
            if(!a) a=t;
            t->data=b[i];
            if(st[0])
            switch (sign)
            {
            case 0:
                st[top-1]->lchild=t;
                break;
            case 1:
                st[top-1]->rchild=t;
                break;
            }
            break;
        }
        ++i;
    }
    return a;
}

void DestoryTree(Tree *a)
{
    if(a)
    {
        DestoryTree(a->lchild);
        DestoryTree(a->rchild);
        free(a);
    }
}

void PreOrderTraverse(Tree *a)
{
    if(a) printf("%c\n",a->data);
    else return;
    PreOrderTraverse(a->lchild);
    PreOrderTraverse(a->rchild);
}

void FindNode(Tree *a,char b,Tree **c)
{
    if(!a) return;
    else if(a->data==b) *c=a;
    else
    {
        FindNode(a->lchild,b,&*c);
        FindNode(a->rchild,b,&*c);
    }
}