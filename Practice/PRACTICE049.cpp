#include <iostream>

template <class T>
class BSTNode
{
private:
    T data;
    BSTNode *lchild, *rchild;

public:
};

template <class T>
class BSTree
{
private:
    BSTNode<T> *root;

public:
    BSTree();
    ~BSTree();

    void InsertNode(T a);
    void DeleteNode(T a);
    void FindNode(T a);

    void PreOrderTra();
    void InOrderTra();
    void PostOrderTra();
};

// template <class T>
// BSTree::BSTree()
// {
//     root =
// }