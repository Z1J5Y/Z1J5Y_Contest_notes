//对于邻接节点数小于二的图生成二叉树
//可修改为普通树




#include<iostream>
#include<vector>
#include<deque>

struct BTNode
{
    int data;
    BTNode *lchild;
    BTNode *rchild;
    BTNode(int t=0)
    {
        data=t;
        lchild=rchild=NULL;
    }
};

std::vector<std::vector<int>> graph;
std::vector<int> deep(2);
std::vector<bool> visit;
std::deque<BTNode*> queue;

int n,m,k;

void maxdeep(BTNode *t,int depth)
{
    if(t)
    {
        depth++;
        if(depth>deep[0]) {deep[0]=depth;deep[1]=t->data;}
        else if(depth==deep[0]&&deep[1]>t->data) {deep[1]=t->data;}
        if(t->lchild) maxdeep(t->lchild,depth);
        if(t->rchild) maxdeep(t->rchild,depth);

    }
}

void query(int k)
{
    int depth=-1;
    queue.clear();
    deep[0]=deep[1]=0;
    visit.resize(n+1);
    for(int i=1;i<=n;++i) visit[i]=false;
    visit[k]=true;
    BTNode *root=new BTNode(k);
    bool flag=true;
    for(auto it=graph[root->data].begin();it!=graph[root->data].end();++it)
    {
        if(!visit[*it])
        {
            if(flag)
            {
                root->lchild=new BTNode(*it);
                queue.push_back(root->lchild);
                flag=false;
            }
            else
            {
                root->rchild=new BTNode(*it);
                queue.push_back(root->rchild);
            }
            visit[*it]=true;
        }
    }

    while(!queue.empty())
    {
        bool flag=true;
        for(auto it=graph[queue.front()->data].begin();it!=graph[queue.front()->data].end();++it)
        {
            if(!visit[*it])
            {
                if(flag)
                {
                    queue.front()->lchild=new BTNode(*it);
                    queue.push_back(queue.front()->lchild);
                    flag=false;
                }
                else
                {
                    queue.front()->rchild=new BTNode(*it);
                    queue.push_back(queue.front()->rchild);
                }
                visit[*it]=true;
            }
        }
        queue.pop_front();
    }

    
    maxdeep(root,depth);
}



int main()
{
    std::cin>>n>>m>>k;
    graph.resize(n+1);
    int t1,t2;
    for(int i=0;i<m;++i)
    {
        std::cin>>t1>>t2;
        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }
    while(k--)
    {
        std::cin>>t1;
        deep[0]=deep[1]=0;
        query(t1);
        printf("%d\n",deep[1]);
    }

    return 0;
}
