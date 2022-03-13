#include<iostream>
//邻接表存储图
const int MAX_VEX_NUM=20;
struct ArcNode
{
    int adjVex;
    int weight;
    ArcNode *next;
};
struct VexNode
{
    int data;
    ArcNode *FirstArc;
};
struct Graph
{
    VexNode Vex[MAX_VEX_NUM];
    int kind;
    int VexNum,ArcNum;
};
struct QNode
{
    int data;
    QNode *next;
};
struct Queue
{
    QNode *front,*rear;
};

void CreatGraph(Graph *&);
void DFS(const Graph *,int );
void DFSTraverse(const Graph *);
void BFSTraverse(const Graph *);
void InitQueue(Queue *&);
inline void EnQueue(Queue *&,int );
inline void DeQueue(Queue *&,int &);
void DestroyQueue(Queue *&);

bool visited[MAX_VEX_NUM]{};

int main()
{
    Graph *EX=NULL;
    CreatGraph(EX);
    DFSTraverse(EX);
    std::cout<<std::endl;
    BFSTraverse(EX);
    return 0;
}

void CreatGraph(Graph *&a)
{
    a=new Graph{};
    std::cout<<"输入节点数量:";
    std::cin>>a->VexNum;
    std::cout<<"输入弧数量:";
    std::cin>>a->ArcNum;
    std::cout<<"输入图的类型:";
    std::cin>>a->kind;//这里默认有向图

    int i,j,t;
    ArcNode *temp;
    for(i=0;i<a->VexNum;++i) a->Vex[i].data=i;
    for(int flag=0;flag<a->ArcNum;++flag)
    {
        std::cout<<"输入边依附的两个节点和权值,无权值则输入0:";
        std::cin>>i>>j>>t;

        temp=new ArcNode{};
        temp->adjVex=j;
        if(t) temp->weight=t;
        temp->next=a->Vex[i].FirstArc;
        a->Vex[i].FirstArc=temp;
    }
    return ;
}

void DFS(const Graph *a,int b)
{
    ArcNode *t=NULL;
    visited[a->Vex[b].data]=1;
    std::cout<<a->Vex[b].data<<' ';
    for(t=a->Vex[b].FirstArc;t;t=t->next)
        if(!visited[t->adjVex])
            DFS(a,t->adjVex);
}

void DFSTraverse(const Graph *a)
{
    for(int i=0;i<a->VexNum;++i)
        if(!visited[i])
            DFS(a,i);
}

void BFSTraverse(const Graph *a)
{
    int i;
    int temp;
    for(i=0;i<a->VexNum;++i)
        visited[i]=0;
    Queue *q=new Queue{};
    InitQueue(q);
    for(i=0;i<a->VexNum;++i)
    {
        if(!visited[i])
        {
            visited[i]=1;
            std::cout<<a->Vex[i].data<<' ';
            EnQueue(q,i);
        }
        while(q->front!=q->rear)
        {
            DeQueue(q,temp);
            for(ArcNode *j=a->Vex[temp].FirstArc;j;j=j->next)
            {
                if(!visited[j->adjVex])
                {
                    visited[j->adjVex]=1;
                    EnQueue(q,j->adjVex);
                    std::cout<<a->Vex[j->adjVex].data<<' ';
                }
            }
        }
    }
    DestroyQueue(q);
}

void InitQueue(Queue *&a)
{
    a->rear=a->front=new QNode{};
}
inline void EnQueue(Queue *&a,int b)
{
    QNode *t=new QNode{b,NULL};
    a->rear->next=t;
    a->rear=t;
}
inline void DeQueue(Queue *&a,int &b)
{
    QNode *temp=a->front->next;
    delete a->front;
    a->front=temp;
    b=a->front->data;
}
void DestroyQueue(Queue *&a)
{
    while(a->front)
    {
        a->rear=a->front->next;
        delete a->front;
        a->front=a->rear;
    }
}