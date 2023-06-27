#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x)
{
    // Write your code here.
    BinaryTreeNode<int> *p = node;
    int res = -1;

    while (p)
    {
        if (p->data == x)
        {
            res = x;
            break;
        }
        else if (p->data < x)
            p = p->right;
        else
        {
            res = p->data;
            p = p->left;
        }
    }
    return res;
}