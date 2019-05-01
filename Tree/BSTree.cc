#include <iostream>
#include "tree.h"
// in tree.h, we defined virutal class BTree

class BSTree : public BiTree
{
public:
    BSTree(BTreeNode *newNode, int newData)
    {
        this->dad = newNode;
        this->dad->data = newData;
    }
    void addNewNode();
    void deleteNode();
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
private:
    BTreeNode *dad;
};

class AVLTree : public BSTree
{};

class RBTree : public BSTree
{};