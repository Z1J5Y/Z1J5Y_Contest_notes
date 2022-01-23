#include<iostream>
#include<vector>
#include<deque>

struct BTNode
{
    int data;
    BTNode *lchild;
    BTNode *rchild;
};

std::vector<int> post,in;
int num;

BTNode *CreatBT(int i,int j,int m,int n)
{
    if(m>n||i>j) return NULL;
    BTNode *node=new BTNode;
    node->data=post[n];
	int t;
    for(t=i;post[n]!=in[t]&&t<=j;++t);
    node->lchild=CreatBT(i,t-1,m,m+t-i-1);
    node->rchild=CreatBT(t+1,j,m+t-i,n-1);

    return node;
}

void Levelorder(BTNode *a)
{
    if(a)
	{
		BTNode *temp=a;
		printf("%d ");
		std::deque<BTNode*> queue;
		if(temp->lchild) queue.push_back(temp->lchild);
		if(temp->rchild) queue.push_back(temp->rchild);
		while(!queue.empty())
		{
			temp=queue[0];
			queue.pop_front();
			printf(" %d",temp->data);
			if(temp->lchild) queue.push_back(temp->lchild);
			if(temp->rchild) queue.push_back(temp->rchild);
		}
	}
}


int main()
{
    std::cin>>num;
    post.resize(num);
    in.resize(num);
    for(int i=0;i<num;++i)
        std::cin>>post[i];
    for(int i=0;i<num;++i)
        std::cin>>in[i];

    BTNode *head=CreatBT(0,num-1,0,num-1);

    Levelorder(head);

    
    return 0;
}