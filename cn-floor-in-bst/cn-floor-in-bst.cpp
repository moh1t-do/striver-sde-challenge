#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> *root, int x)
{
    // Write your code here.
    int res = -1;
    TreeNode<int> *p = root;

    while (p)
    {
        if (p->val == x)
        {
            res = p->val;
            break;
        }
        else if (p->val < x)
        {
            res = p->val;
            p = p->right;
        }
        else
            p = p->left;
    }

    return res;
}