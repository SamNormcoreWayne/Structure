#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

struct BTreeNode
{
    BTreeNode(int data = 0, BTreeNode *left=nullptr, BTreeNode *right=nullptr)
    {};
    BTreeNode *left=nullptr, *right=nullptr;
    int data;
};

class BiTree
{
public:
    BiTree(){}
    virtual void addNewNode();
    virtual void preOrderTraversal();
    virtual void inOrderTraversal();
    virtual void postOrderTraversal();
};