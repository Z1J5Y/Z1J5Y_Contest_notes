//树的3种存储结构及部分深度求法
#include<stdio.h>
#include<stdlib.h>

typedef struct TYPE1
{
    char data;
    int parents;
}Type1;

typedef struct TYPE2
{
    char data;
    struct TYPE2 *son[3];
}Type2;

typedef struct TYPE3
{
    char data;
    struct TYPE3 *hp,*vp;//hp指向兄弟 vp指向孩子
}Type3;

int TreeDepth1(Type1 *);
int TreeDepth2(Type2 *);
int TreeDepth3(Type3 *);

int main()
{
    Type1 *tree1;
    tree1=calloc(7,sizeof(Type1));
    for(int i=0;i<7;++i)
    {
        tree1[i].data='A'+i;
        if(i<1) tree1[i].parents=-1;
        else if(i<4) tree1[i].parents=0;
        else if(i<7) tree1[i].parents=2;
    }
    for(int i=0;i<7;++i) printf("%c %d\n",tree1[i].data,tree1[i].parents);
    printf("tree1 depth=%d\n",TreeDepth1(tree1));

    Type2 *tree2=calloc(1,sizeof(Type2));
    tree2->data='A';
    tree2->son[0]=calloc(1,sizeof(Type2));
    tree2->son[0]->data='B';
    tree2->son[1]=calloc(1,sizeof(Type2));
    tree2->son[1]->data='C';
    tree2->son[2]=calloc(1,sizeof(Type2));
    tree2->son[2]->data='D';
    tree2->son[1]->son[0]=calloc(1,sizeof(Type2));
    tree2->son[1]->son[0]->data='E';
    tree2->son[1]->son[1]=calloc(1,sizeof(Type2));
    tree2->son[1]->son[1]->data='F';
    tree2->son[1]->son[2]=calloc(1,sizeof(Type2));
    tree2->son[1]->son[2]->data='G';
    for(int i=0;i<7;++i)
    {
        if(i<1) printf("%c \n",tree2->data);
        else if(i<4) printf("%c \n",tree2->son[i-1]->data);
        else if(i<7) printf("%c \n",tree2->son[1]->son[i-4]->data);
    }
    printf("tree2 depth=%d",TreeDepth2(tree2));

    Type3 *tree3=calloc(1,sizeof(Type3));
    tree3->data='A';
    tree3->vp=calloc(1,sizeof(Type3));
    tree3->vp->data='B';
    tree3->vp->hp=calloc(1,sizeof(Type3));
    tree3->vp->hp->data='C';
    tree3->vp->hp->hp=calloc(1,sizeof(Type3));
    tree3->vp->hp->hp->data='D';
    tree3->vp->hp->vp=calloc(1,sizeof(Type3));
    tree3->vp->hp->vp->data='E';
    tree3->vp->hp->vp->hp=calloc(1,sizeof(Type3));
    tree3->vp->hp->vp->hp->data='F';
    tree3->vp->hp->vp->hp->hp=calloc(1,sizeof(Type3));
    tree3->vp->hp->vp->hp->hp->data='G';
    printf("\ntree3 depth=%d",TreeDepth3(tree3));

    return 0;
}

int TreeDepth1(Type1 *a)
{
    int depth=0;
    for(Type1 *t=a;t->data!='G';t+=1) if(t->parents>depth) depth=t->parents;
    return depth+1;
}

int TreeDepth2(Type2 *a)
{
    if(!a) return 0;

    int depth,mdepth=0;

    for(int i=0;i<3;++i)
    {
        depth=TreeDepth2(a->son[i]);
        if(depth>mdepth) mdepth=depth;
    }

    return mdepth+1;
}

int TreeDepth3(Type3 *a)
{
    if(!a) return 0;
    int depth,mdepth=0;
    Type3 *t=a->vp;

    for(;t!=NULL;t=t->hp)
    {
        depth=TreeDepth3(t);
        if(depth>mdepth) mdepth=depth;
    }

    return mdepth+1;
}