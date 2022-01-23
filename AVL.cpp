#include<iostream>

class AVL
{
private:
    AVL *rchild,*lchild;
    int bf;
    int data;
public:
    AVL(int data,AVL *r=NULL,AVL *l=NULL);
    ~AVL();

    void R_Rotate();
    void L_Rotate();
    AVL *LeftBalance();
    AVL *RightBalance();
    bool InsertValue(int data,bool &taller);
};

AVL::AVL(int data,AVL *r=NULL,AVL *l=NULL)
{
    this->data=data;
    rchild=r;
    lchild=l;
    bf=0;
}

AVL::~AVL()
{
}

void AVL::R_Rotate()
{
    AVL *L=this->lchild;
    this->lchild=L->rchild;
    L->rchild=this;
}
void AVL::L_Rotate()
{
    AVL *R=this->rchild;
    this->rchild=R->lchild;
    R->lchild=this;
}
AVL *AVL::LeftBalance()
{
    AVL *L;
    L=this->lchild;
    switch (L->bf)
    {
    case 1:
        this->bf=L->bf=0;
        this->R_Rotate();
        break;
    case -1:
        AVL *t=L->rchild;
        switch (t->bf)
        {
        case 1:
            this->bf=-1;
            L->bf=0;
            break;
        case 0:
            this->bf=L->bf=0;
            break;
        case -1:
            this->bf=0;
            L->bf=1;
            break;
        default:
            break;
        }
        t->bf=0;
        this->lchild->L_Rotate();
        this->R_Rotate();
        break;
    default:
        break;
    }
}

AVL *AVL::RightBalance()
{

}