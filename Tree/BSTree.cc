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
    void addNewNode(int );
    bool search(int );
    void deleteNode(int );
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
private:
    BTreeNode *dad;
};

void BSTree::addNewNode(int newData)
{
    BTreeNode *tmpNode = this->dad;
    while (true)
    {
        if (newData < tmpNode->data)
        {
            if (tmpNode->left != nullptr)
                tmpNode = tmpNode->left;
            else
            {
                tmpNode->left = new BTreeNode(newData);
                break;
            }
        }
        else
        {
            if (tmpNode->right != nullptr)
                tmpNode = tmpNode->right;
            else
            {
                tmpNode->right = new BTreeNode(newData);
                break;
            }
        }
    }
}

bool BSTree::search(int some)
{
    BTreeNode *tmpNode = this->dad;
    while(true)
    {
        if (tmpNode == nullptr)
            return false;
        if (some < tmpNode->data)
            tmpNode = tmpNode->left;
        if (some > tmpNode->data)
            tmpNode = tmpNode->right;
        if (some == tmpNode->data)
            return true;
    }
}

void BSTree::deleteNode(int oldData)
{

}