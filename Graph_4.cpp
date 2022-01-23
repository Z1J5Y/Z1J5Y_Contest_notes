#include<iostream>
//邻接多重表存储图
const int MAX_VEX_NUM=20;

struct ArcNode
{
    int i,j;
    ArcNode *ilink,*jlink;
    int weight;
};

struct VexNode
{
    int data;
    ArcNode *FirstArc;
};

struct Graph
{
    int ArcNum,VexNum;
    int kind;
    VexNode Vex[MAX_VEX_NUM];
};

void CreatGraph(Graph *&);
void DFS(Graph *,int );
void DFSTraverse(Graph *);

bool visited[MAX_VEX_NUM]{};

int main()
{
    Graph *EX=NULL;
    CreatGraph(EX);

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
        temp->i=i;
        temp->j=j;
        if(t) temp->weight=t;
        temp->ilink=a->Vex[i].FirstArc;
        a->Vex[i].FirstArc=temp;
        temp->jlink=a->Vex[j].FirstArc;
        a->Vex[j].FirstArc=temp;
    }
    return ;
}

// #include <stdio.h>
// #define MAX_VERTEX_NUM 30 /* 图中顶点数的最大值*/
// #define OK 1
// #define TRUE 1
// #define ERROR 0
// #define FALSE 0
// #define null 0

// int Visited[MAX_VERTEX_NUM]; /*访问标志数组(全局量) 用于访问标记*/
// char Edge[2 * MAX_VERTEX_NUM];

// int i = 0;
// int j = 0;

// typedef struct Qnode //链队结点的类型及指针
// {
// 	int data;
// 	struct Qnode *next;
// } Qnode, *LinkedQnode;
// typedef struct Queue //将头尾指针封装在一起的链队
// {
// 	struct Qnode *front, *rear;
// } Queue;
// void InitQueue(Queue Q) //初始化队列
// {
// 	Q.front = Q.rear = (LinkedQnode)malloc(sizeof(Qnode));
// 	Q.front->next = null;
// }
// int DestroyQueue(Queue Q) //销毁队列
// {
// 	while (Q.front != null)
// 	{
// 		Q.rear = Q.front->next;
// 		free(Q.front);
// 		Q.front = Q.rear;
// 	}
// 	return OK;
// }
// int QueueEmpty(Queue Q) //判断队列是否为空
// {
// 	if (Q.front == Q.rear)
// 		return OK;
// 	else
// 		return ERROR;
// }
// void EnQueue(Queue Q, int e) //入队
// {
// 	Qnode *pt;
// 	pt = (LinkedQnode)malloc(sizeof(Qnode));
// 	pt->data = e;
// 	pt->next = null;
// 	Q.rear->next = pt;
// 	Q.rear = pt;
// }
// void DeQueue(Queue Q, int e) //出队
// {
// 	Qnode *ps;
// 	ps = Q.front->next;
// 	e = ps->data;
// 	if (ps->next == null)
// 	{
// 		Q.front->next = null;
// 		Q.front = Q.rear;
// 	}
// 	else
// 		Q.front->next = ps->next;
// }
// enum VisitIf
// {
// 	unvisited,
// 	visited
// };					//定义枚举类型
// typedef struct Ebox //定义边结点
// {
// 	int mark;
// 	int ivex, jvex;		//该边依附的两个顶点的位置
// 	struct Ebox *ilink; //i,j顶点分别指向的下一条边
// 	struct Ebox *jlink;
// 	char *info; //和边有关的信息
// } Ebox, *linkedEbox;
// typedef struct Vexbox //定义顶点结点
// {
// 	char data;		 //数据域
// 	Ebox *firstedge; //指向第一个邻接点的指针
// } Vexbox;
// typedef struct AMLGraph //邻接多重表
// {
// 	Vexbox adjmulist[MAX_VERTEX_NUM];
// 	int vexnum, edgenum;
// } AMLGraph;
// int LocateVex(AMLGraph G, char u) //在邻接多重表定位u顶点
// {
// 	int i;
// 	for (i = 0; i < G.vexnum; i++)
// 		if (u == G.adjmulist[i].data)
// 			return i;
// 	return -1;
// }
// /*返回v的顶点值*/

// int FirstAdjvex(AMLGraph G, char v) //寻找v点的第一邻接点
// {
// 	int i;
// 	i = LocateVex(G, v); //定位V顶点
// 	if (i < 0)
// 		return -1;
// 	else if (G.adjmulist[i].firstedge != NULL) //说明该顶点存在邻接点
// 	{
// 		if (G.adjmulist[i].firstedge->ivex == i) //如果该顶点所接边的ivex是i的话
// 		{
// 			return G.adjmulist[i].firstedge->jvex; //该顶点的邻接点是jvex
// 		}
// 		else
// 			return G.adjmulist[i].firstedge->ivex; //否则该顶点的邻接点是ivex
// 	}
// 	else
// 		return -1;
// }
// int NextAdjvex(AMLGraph G, char v, char w) //寻找v顶点的邻接点w的下一邻接点
// {
// 	int i, j;
// 	Ebox *p;
// 	i = LocateVex(G, v); //分别寻找i顶点和j顶点
// 	j = LocateVex(G, w);
// 	if (i < 0 || j < 0)
// 		return -1;
// 	p = G.adjmulist[i].firstedge;
// 	while (p != null)
// 		if (p->ivex == i && p->jvex != j)
// 			p = p->ilink;
// 		else if (p->jvex == i && p->ivex != j)
// 			p = p->jlink;
// 		else
// 			break;
// 	if (p && p->ivex == i && p->jvex == j)
// 	{
// 		p = p->ilink;
// 		if (p && p->ivex == i)
// 			return p->jvex;
// 		else if (p && p->jvex == i)
// 			return p->ivex;
// 	}
// 	if (p && p->ivex == j && p->jvex == i)
// 	{
// 		p = p->jlink;
// 		if (p && p->ivex == i)
// 			return p->jvex;
// 		else if (p && p->jvex == i)
// 			return p->ivex;
// 	}
// 	return -1;
// }
// /* 采用邻接多重表存储结构,构造无向图G */
// void CreateGraph(AMLGraph G)
// {
// 	int i, j, k, cur = 0;
// 	char va, vb;
// 	Ebox *p;
// 	printf("请输入图的顶点数:\n");
// 	scanf("%d", &G.vexnum);
// 	printf("请输入图的边数:\n");
// 	scanf("%d", &G.edgenum);
// 	printf("请输入%d个顶点的数值\n", G.vexnum);
// 	for (i = 0; i < G.vexnum; ++i)
// 	{
// 		scanf("%c", &G.adjmulist[i].data);
// 		G.adjmulist[i].firstedge = null;
// 	}
// 	printf("输入一条边上两个顶点的信息:\n");
// 	for (k = 0; k < G.edgenum; ++k) /* 构造表结点链表 */
// 	{
// 		scanf("%c%c", &va, &vb); /* 读入两个顶点*/
// 		Edge[cur++] = va;
// 		Edge[cur++] = vb;
// 		i = LocateVex(G, va); /* 一端 */
// 		j = LocateVex(G, vb); /* 另一端 */
// 		p = (linkedEbox)malloc(sizeof(Ebox));
// 		p->mark = unvisited; /* 设初值 */
// 		p->ivex = i;
// 		p->jvex = j;
// 		p->info = null;
// 		p->ilink = null;
// 		p->jlink = null;
// 		p->ilink = G.adjmulist[i].firstedge; /* 插在表头 */
// 		G.adjmulist[i].firstedge = p;
// 		p->jlink = G.adjmulist[j].firstedge; /* 插在表头 */
// 		G.adjmulist[j].firstedge = p;		 /*插入j链表尾部*/
// 	}
// }
// void DFS(AMLGraph G, int v) //从顶点v开始深度优先遍历
// {
// 	char u;
// 	int w;
// 	Visited[v] = 1;					   //遍历后v点标志域改为1
// 	printf("%c", G.adjmulist[v].data); //打印该点
// 	u = G.adjmulist[v].data;
// 	for (w = FirstAdjvex(G, u); w; w = NextAdjvex(G, u, G.adjmulist[w].data))
// 		if (Visited[w] == 0)
// 		{
// 			printf("%c--%c\n", G.adjmulist[v].data, G.adjmulist[w].data);
// 			DFS(G, w);
// 		}
// }
// void DFSTraverse(AMLGraph G, char start)
// {
// 	int v, z;
// 	for (v = 0; v < G.vexnum; v++)
// 		Visited[v] = 0; //令所有标志域都为0
// 	z = LocateVex(G, start);
// 	for (v = 0; v < G.vexnum; v++)
// 		if (Visited[(v + z) % G.vexnum] == 0)
// 			DFS(G, (v + z) % G.vexnum);
// }

// void BFSTraverse(AMLGraph G, char start)
// {
// 	Queue Q;
// 	int u, z, w, v;
// 	for (v = 0; v < G.vexnum; v++)
// 		Visited[v] = 0;
// 	InitQueue(Q);
// 	z = LocateVex(G, start);
// 	for (v = 0; v < G.vexnum; v++)
// 		if (Visited[(v + z) % G.vexnum] == 0)
// 		{
// 			Visited[(v + z) % G.vexnum] = 1;
// 			printf("%c\n", G.adjmulist[(v + z) % G.vexnum].data);
// 			EnQueue(Q, (v + z) % G.vexnum);
// 			while (!QueueEmpty(Q))
// 			{
// 				DeQueue(Q, u);
// 				for (w = FirstAdjvex(G, G.adjmulist[u].data); w; w = NextAdjvex(G, G.adjmulist[u].data, G.adjmulist[w].data))
// 					if (Visited[w] == 0)
// 					{
// 						Visited[w] = 1;
// 						printf("%c--%c\n", G.adjmulist[u].data, G.adjmulist[w].data);
// 						printf("%c\n", G.adjmulist[w].data);
// 						EnQueue(Q, w);
// 					}
// 			}
// 		}
// 	DestroyQueue(Q);
// }

// void main()
// {
// 	AMLGraph G;
// 	char start;
// 	CreateGraph(G);
// 	printf("输入要开始搜索的点:\n");
// 	scanf("%c", &start);
// 	printf("深度优先搜索:");
// 	DFSTraverse(G, start);
// 	printf("广度优先搜索:");
// 	BFSTraverse(G, start);
// }