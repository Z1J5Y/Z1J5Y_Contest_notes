#include<stdio.h>
#include<stdlib.h>

#define MAX_TREE_SIZE 256;

typedef struct BitNode{
    char data;
    BitNode *lchild,*rchild;
}Bitree;

void CreateBitree(Bitree *&T){
	char s;
	scanf("%c",&s);
	if(s=='#')
		T=NULL;
	else{
		T=(Bitree*)malloc(sizeof(struct BitNode));
		T->data=s;
		CreateBitree(T->lchild);
		CreateBitree(T->rchild);
	}
}

int tdegree(Bitree *T)
{
	if(!T) return 0;
	else if(T->rchild==NULL&&T->lchild==NULL) return 1;
	else if(T->lchild&&T->rchild) return 2;
	else
	{
		int ldegree=tdegree(T->lchild);
		int rdegree=tdegree(T->rchild);
		return (ldegree>rdegree?ldegree:rdegree);
	}
}

int degree(Bitree *T)
{
	if(!T||T->rchild==NULL&&T->lchild==NULL) return 0;
	else if(T->lchild&&T->rchild) return 2;
	else
	{
		int ldegree=tdegree(T->lchild);
		int rdegree=tdegree(T->rchild);
		return (ldegree>rdegree?ldegree:rdegree);
	}
}

void deep(Bitree*T,int deepth,int &maxdeepth){  
	if(T!=NULL){
		deepth++;
		if(deepth>maxdeepth) maxdeepth=deepth;

		deep(T->lchild,deepth,maxdeepth);
		deep(T->rchild,deepth,maxdeepth);
	}

	return ;
}

int wide(Bitree *T)
{
	BitNode *queue[200]{};
	int front=0,rear=0;
	int maxwidth=1,width=0;
	queue[rear++]=T;
	BitNode *temp,*tlastNode=T,*nlastNode;

	while(front!=rear)
	{
		temp=queue[front++];
		width++;

		if(width>maxwidth) maxwidth=width;
		if(temp->lchild) 
			nlastNode=queue[rear++]=temp->lchild;
		if(temp->rchild)
			nlastNode=queue[rear++]=temp->rchild;
		if(temp==tlastNode)
		{
			tlastNode=nlastNode;
			width=0;
		}
	}

	return maxwidth;
}

int main( ){
	BitNode *root;
	CreateBitree(root);

	int maxdeepth=0;
	deep(root,0,maxdeepth);

	printf("deepth:%d\n",maxdeepth);

	int maxwidth=wide(root);
	printf("width:%d\n",maxwidth);

	printf("degree:%d\n",degree(root));

	return 0;
}

