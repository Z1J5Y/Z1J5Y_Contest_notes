#include<iostream>
//十字链表存储图
const int MAX_VEX_NUM=20;

struct ArcNode
{
    int HeadVex,TailVex;
    ArcNode *HeadLink,*TailLink;
    int weight;
};
struct VexNode
{
    int data;
    ArcNode *FirstIn,*FirstOut;
};
struct Graph
{
    VexNode Vex[MAX_VEX_NUM];
    int kind,VexNum,ArcNum;
};

void CreatGraph(Graph *&);

int main()
{
    Graph *EX;
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
        if(t) temp->weight=t;
        temp->HeadVex=j;
        temp->TailVex=i;
        temp->HeadLink=a->Vex[j].FirstIn;
        temp->TailLink=a->Vex[i].FirstOut;
        a->Vex[i].FirstOut=temp;
        a->Vex[j].FirstIn=temp;
    }


    return ;
}