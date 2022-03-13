#include<cstdio>
#include<cstdlib>
#include<vector>
struct BiTNode
{
    char data;
    struct BiTNode *lchild,*rchild;
};

struct BiTNode* CreatBinTree()
{
    struct BiTNode *t;
    char ch;

    if((ch=getchar())=='*') t=NULL;
    else
    {
        t=(struct BiTNode *)calloc(1,sizeof(struct BiTNode));
        t->data=ch;
        t->lchild=CreatBinTree();
        t->rchild=CreatBinTree();
    }

    return t;
}
void PreOrder(struct BiTNode *t)
{
    if(t)
    {
        printf("%c ",t->data);
        PreOrder(t->lchild);
        PreOrder(t->rchild);
    }
    return ;
}
void PreOrder2(struct BiTNode *head)
{
    std::vector<BiTNode*> stack;
    BiTNode *temp=head;
    int top=-1;
    while(!stack.empty()||temp!=NULL)
    {
        while(temp!=NULL)
        {
            printf("%c ",temp->data);
            stack.push_back(temp);
            top++;
            temp=temp->lchild;
        }

        if(!stack.empty())
        {
            temp=stack[top--];
            stack.pop_back();
            temp=temp->rchild;
        }
    }
    return ;
}
void MidOrder(struct BiTNode *t)
{
    if(t)
    {
        MidOrder(t->lchild);
        printf("%c ",t->data);
        MidOrder(t->rchild);
    }
    return ;
}
void MidOrder2(struct BiTNode *head)
{
    std::vector<BiTNode*> stack;
    BiTNode *temp=head;
    int top=-1;
    while(!stack.empty()||temp)
    {
        while(temp!=NULL)
        {
            stack.push_back(temp);
            top++;
            temp=temp->lchild;
        }
        if(!stack.empty())
        {
            temp=stack[top--];
            stack.pop_back();
            printf("%c ",temp->data);
            temp=temp->rchild;
        }
    }
    return ;
}

void PostOrder(struct BiTNode *t)
{
    if(t)
    {
        PostOrder(t->lchild);
        PostOrder(t->rchild);
        printf("%c ",t->data);
    }
    return ;
}
void PostOrder2(struct BiTNode *head)
{
    std::vector<BiTNode*> stack;
    BiTNode *temp=head,*pre=NULL,*t;
    int top=-1;

    while(temp||!stack.empty())
    {
        while(temp)
        {
            stack.push_back(temp);
            top++;
            temp=temp->lchild;
        }
        t=stack[top];
        if(!(t->rchild)||t->rchild==pre)
        {
            printf("%c ",t->data);
            pre=t;
            stack.pop_back();
            top--;
            temp=NULL;
        }
        else
            temp=t->rchild;
    }

    return ;
}

int main()
{
    struct BiTNode *head=CreatBinTree();
    PreOrder2(head);
    putchar('\n');
    MidOrder2(head);
    putchar('\n');
    PostOrder2(head);
    putchar('\n');

	return 0;
}