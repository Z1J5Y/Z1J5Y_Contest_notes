#include<iostream>
//邻接矩阵存储图
const int MAX_VEX_NUM=20;

struct MatrixNode
{
    int weight,arc;
};
struct Graph
{
    MatrixNode arcs[MAX_VEX_NUM][MAX_VEX_NUM];
    int VEX[MAX_VEX_NUM];
    int kind,ArcNum,VexNum;
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

struct Prim
{
    int adjvex,lowcost;
};

void CreatGraph(Graph *&);
void DFSTraverse(const Graph*);
void DFS(const Graph *,int );
void BFSTraverse(const Graph *);
void InitQueue(Queue *&);
inline void EnQueue(Queue *&,int );
inline void DeQueue(Queue *&,int &);
void DestroyQueue(Queue *&);
void MiniTree_Prim(Graph *&,int);

bool visited[MAX_VEX_NUM]{};

int main()
{
    Graph *EX=NULL;
    CreatGraph(EX);
    //DFSTraverse(EX);
    //std::cout<<std::endl;
    //BFSTraverse(EX);
    MiniTree_Prim(EX,0);

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
    std::cin>>a->kind;//这里默认无向图

    int i,j,t;
    for(i=0;i<a->VexNum;++i)
        a->VEX[i]=i;
    for(int flag=0;flag<a->ArcNum;++flag)
    {
        std::cout<<"输入边依附的两个节点和权值,无权值则输入0:";
        std::cin>>i>>j>>t;
        if(i!=j&&i<a->VexNum&&i>=0&&j<a->VexNum&&j>=0)
        {
            a->arcs[i][j].arc=a->arcs[j][i].arc=1;
            if(t) a->arcs[i][j].weight=a->arcs[j][i].weight=t;
        }
    }
    for(i=0;i<a->VexNum;++i)
    {
        for(j=0;j<a->VexNum;++j)
        {
            if(a->arcs[i][j].weight==0&&i!=j)
                a->arcs[i][j].weight=a->arcs[j][i].weight=65535;
        }
    }
    return ;
}

void DFS(const Graph *a,int b)
{
    int i;
    visited[b]=1;
    std::cout<<a->VEX[b]<<' ';
    for(i=0;i<a->VexNum;++i)
        if(a->arcs[b][i].arc&&!visited[i])
            DFS(a,i);
}

void DFSTraverse(const Graph*a)
{
    for(int i=0;i<a->VexNum;++i)
        if(!visited[i])
            DFS(a,i);
}

void BFSTraverse(Graph *a)
{
    int i,j;
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
            std::cout<<a->VEX[i]<<' ';
            EnQueue(q,i);
        }
        while(q->front!=q->rear)
        {
            DeQueue(q,temp);
            for(j=0;j<a->VexNum;++j)
            {
                if(a->arcs[temp][j].arc&&!visited[j])
                {
                    visited[j]=1;
                    EnQueue(q,j);
                    std::cout<<a->VEX[j]<<' ';
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

void MiniTree_Prim(Graph *&a,int b)
{
    int min,t;
    Prim closedge[MAX_VEX_NUM]{};
    for(int i=0;i<a->VexNum;++i)
        closedge[i]={b,a->arcs[b][i].weight};
    closedge[b]={-1,0};
    printf("%d\n",b);
    for(int i=1;i<a->VexNum;++i)
    {
        min=65535,t=0;
        for(int j=0;j<a->VexNum;++j)
        {
            if(closedge[j].lowcost&&closedge[j].lowcost<min)
            {
                min=closedge[j].lowcost;
                t=j;
            }
        }
        printf("%d->%d\n",closedge[t].adjvex,closedge[t].lowcost);
        closedge[t].lowcost=0;
        for(int j=0;j<a->VexNum;++j)
        {
            if(a->arcs[t][j].weight<closedge[j].lowcost)
            {
                closedge[j]={t,a->arcs[t][j].weight};
            }
        }
    }
}

//以下为他人之智
//http://data.biancheng.net/view/45.html
//孩子兄弟法生成深度/广度优先生成树

// #include <stdio.h>
// #include <stdlib.h>
// #define MAX_VERtEX_NUM 20                   //顶点的最大个数
// #define VRType int                          //表示顶点之间的关系的变量类型
// #define VertexType int                     //图中顶点的数据类型
// typedef enum{false,true}bool;               //定义bool型常量
// bool visited[MAX_VERtEX_NUM];               //设置全局数组，记录标记顶点是否被访问过
// typedef struct {
//     VRType adj;                             //对于无权图，用 1 或 0 表示是否相邻；对于带权图，直接为权值。
// }ArcCell,AdjMatrix[MAX_VERtEX_NUM][MAX_VERtEX_NUM];
// typedef struct {
//     VertexType vexs[MAX_VERtEX_NUM];        //存储图中顶点数据
//     AdjMatrix arcs;                         //二维数组，记录顶点之间的关系
//     int vexnum,arcnum;                      //记录图的顶点数和弧（边）数
// }MGraph;
// //孩子兄弟表示法的链表结点结构
// typedef struct CSNode{
//     VertexType data;
//     struct CSNode * lchild;//孩子结点
//     struct CSNode * nextsibling;//兄弟结点
// }*CSTree,CSNode;
// //根据顶点本身数据，判断出顶点在二维数组中的位置
// int LocateVex(MGraph G,VertexType v){
//     int i=0;
//     //遍历一维数组，找到变量v
//     for (; i<G.vexnum; i++) {
//         if (G.vexs[i]==v) {
//             break;
//         }
//     }
//     //如果找不到，输出提示语句，返回-1
//     if (i>G.vexnum) {
//         printf("no such vertex.\n");
//         return -1;
//     }
//     return i;
// }
// //构造无向图
// void CreateDN(MGraph *G){
//     scanf("%d,%d",&(G->vexnum),&(G->arcnum));
//     getchar();
//     for (int i=0; i<G->vexnum; i++) {
//         scanf("%d",&(G->vexs[i]));
//     }
//     for (int i=0; i<G->vexnum; i++) {
//         for (int j=0; j<G->vexnum; j++) {
//             G->arcs[i][j].adj=0;
//         }
//     }
//     for (int i=0; i<G->arcnum; i++) {
//         int v1,v2;
//         scanf("%d,%d",&v1,&v2);
//         int n=LocateVex(*G, v1);
//         int m=LocateVex(*G, v2);
//         if (m==-1 ||n==-1) {
//             printf("no this vertex\n");
//             return;
//         }
//         G->arcs[n][m].adj=1;
//         G->arcs[m][n].adj=1;//无向图的二阶矩阵沿主对角线对称
//     }
// }
// int FirstAdjVex(MGraph G,int v)
// {
//     //查找与数组下标为v的顶点之间有边的顶点，返回它在数组中的下标
//     for(int i = 0; i<G.vexnum; i++){
//         if( G.arcs[v][i].adj ){
//             return i;
//         }
//     }
//     return -1;
// }
// int NextAdjVex(MGraph G,int v,int w)
// {
//     //从前一个访问位置w的下一个位置开始，查找之间有边的顶点
//     for(int i = w+1; i<G.vexnum; i++){
//         if(G.arcs[v][i].adj){
//             return i;
//         }
//     }
//     return -1;
// }
// void DFSTree(MGraph G,int v,CSTree*T){
//     //将正在访问的该顶点的标志位设为true
//     visited[v]=true;
//     bool first=true;
//     CSTree q=NULL;
//     //依次遍历该顶点的所有邻接点
//     for (int w=FirstAdjVex(G, v); w>=0; w=NextAdjVex(G, v, w)) {
//         //如果该临界点标志位为false，说明还未访问
//         if (!visited[w]) {
//             //为该邻接点初始化为结点
//             CSTree p=(CSTree)malloc(sizeof(CSNode));
//             p->data=G.vexs[w];
//             p->lchild=NULL;
//             p->nextsibling=NULL;
//             //该结点的第一个邻接点作为孩子结点，其它邻接点作为孩子结点的兄弟结点
//             if (first) {
//                 (*T)->lchild=p;
//                 first=false;
//             }
//             //否则，为兄弟结点
//             else{
//                 q->nextsibling=p;
//             }
//             q=p;
//             //以当前访问的顶点为树根，继续访问其邻接点
//             DFSTree(G, w, &q);
//         }
//     }
// }
// //深度优先搜索生成森林并转化为二叉树
// void DFSForest(MGraph G,CSTree *T){
//     (*T)=NULL;
//     //每个顶点的标记为初始化为false
//     for (int v=0; v<G.vexnum; v++) {
//         visited[v]=false;
//     }
//     CSTree q=NULL;
//     //遍历每个顶点作为初始点，建立深度优先生成树
//     for (int v=0; v<G.vexnum; v++) {
//         //如果该顶点的标记位为false，证明未访问过
//         if (!(visited[v])) {
//             //新建一个结点，表示该顶点
//             CSTree p=(CSTree)malloc(sizeof(CSNode));
//             p->data=G.vexs[v];
//             p->lchild=NULL;
//             p->nextsibling=NULL;
//             //如果树未空，则该顶点作为树的树根
//             if (!(*T)) {
//                 (*T)=p;
//             }
//             //该顶点作为树根的兄弟结点
//             else{
//                 q->nextsibling=p;
//             }
//             //每次都要把q指针指向新的结点，为下次添加结点做铺垫
//             q=p;
//             //以该结点为起始点，构建深度优先生成树
//             DFSTree(G,v,&p);
//         }
//     }
// }
// //前序遍历二叉树
// void PreOrderTraverse(CSTree T){
//     if (T) {
//         printf("%d ",T->data);
//         PreOrderTraverse(T->lchild);
//         PreOrderTraverse(T->nextsibling);
//     }
//     return;
// }
// int main() {
//     MGraph G;//建立一个图的变量
//     CreateDN(&G);//初始化图
//     CSTree T;
//     DFSForest(G, &T);
//     PreOrderTraverse(T);
//     return 0;
// }


// typedef struct Queue{
//     CSTree data;//队列中存放的为树结点
//     struct Queue * next;
// }Queue;
// //初始化队列
// void InitQueue(Queue ** Q){
//     (*Q)=(Queue*)malloc(sizeof(Queue));
//     (*Q)->next=NULL;
// }
// //结点v进队列
// void EnQueue(Queue **Q,CSTree T){
//     Queue * element=(Queue*)malloc(sizeof(Queue));
//     element->data=T;
//     element->next=NULL;

//     Queue * temp=(*Q);
//     while (temp->next!=NULL) {
//         temp=temp->next;
//     }
//     temp->next=element;
// }
// //队头元素出队列
// void DeQueue(Queue **Q,CSTree *u){
//     (*u)=(*Q)->next->data;
//     (*Q)->next=(*Q)->next->next;
// }
// //判断队列是否为空
// bool QueueEmpty(Queue *Q){
//     if (Q->next==NULL) {
//         return true;
//     }
//     return false;
// }
// void BFSTree(MGraph G,int v,CSTree*T){
//     CSTree q=NULL;
//     Queue * Q;
//     InitQueue(&Q);
//     //根结点入队
//     EnQueue(&Q, (*T));
//     //当队列为空时，证明遍历完成
//     while (!QueueEmpty(Q)) {
//         bool first=true;
//         //队列首个结点出队
//         DeQueue(&Q,&q);
//         //判断结点中的数据在数组中的具体位置
//         int v=LocateVex(&G,q->data);
//         //已经访问过的更改其标志位
//         visited[v]=true;
//         //遍历以出队结点为起始点的所有邻接点
//         for (int w=FirstAdjVex(G,v); w>=0; w=NextAdjVex(G,v, w)) {
//             //标志位为false，证明未遍历过
//             if (!visited[w]) {
//                 //新建一个结点 p，存放当前遍历的顶点
//                 CSTree p=(CSTree)malloc(sizeof(CSNode));
//                 p->data=G.vexs[w];
//                 p->lchild=NULL;
//                 p->nextsibling=NULL;
//                 //当前结点入队
//                 EnQueue(&Q, p);
//                 //更改标志位
//                 visited[w]=true;
//                 //如果是出队顶点的第一个邻接点，设置p结点为其左孩子
//                 if (first) {
//                     q->lchild=p;
//                     first=false;
//                 }
//                 //否则设置其为兄弟结点
//                 else{
//                     q->nextsibling=p;
//                 }
//                 q=p;
//             }
//         }
//     }
// }
// //广度优先搜索生成森林并转化为二叉树
// void BFSForest(MGraph G,CSTree *T){
//     (*T)=NULL;
//     //每个顶点的标记为初始化为false
//     for (int v=0; v<G.vexnum; v++) {
//         visited[v]=false;
//     }
//     CSTree q=NULL;
//     //遍历图中所有的顶点
//     for (int v=0; v<G.vexnum; v++) {
//         //如果该顶点的标记位为false，证明未访问过
//         if (!(visited[v])) {
//             //新建一个结点，表示该顶点
//             CSTree p=(CSTree)malloc(sizeof(CSNode));
//             p->data=G.vexs[v];
//             p->lchild=NULL;
//             p->nextsibling=NULL;
//             //如果树未空，则该顶点作为树的树根
//             if (!(*T)) {
//                 (*T)=p;
//             }
//             //该顶点作为树根的兄弟结点
//             else{
//                 q->nextsibling=p;
//             }
//             //每次都要把q指针指向新的结点，为下次添加结点做铺垫
//             q=p;
//             //以该结点为起始点，构建广度优先生成树
//             BFSTree(G,v,&p);
//         }
//     }
// }