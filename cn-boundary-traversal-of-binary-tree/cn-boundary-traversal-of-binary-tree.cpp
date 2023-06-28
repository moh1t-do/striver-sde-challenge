#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isLeaf(TreeNode<int> *rt)
{
    return (!rt->left && !rt->right);
}

void leftBound(TreeNode<int> *rt, vector<int> &left)
{
    TreeNode<int> *cur = rt->left;
    while (cur)
    {
        if (!isLeaf(cur))
            left.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void rightBound(TreeNode<int> *rt, vector<int> &right)
{
    int sz = right.size();
    TreeNode<int> *cur = rt->right;
    while (cur)
    {
        if (!isLeaf(cur))
            right.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    reverse(right.begin() + sz, right.end());
}

void bottomBound(TreeNode<int> *rt, vector<int> &bottom)
{
    if (!rt)
        return;
    if (isLeaf(rt))
    {
        bottom.push_back(rt->data);
        return;
    }
    bottomBound(rt->left, bottom);
    bottomBound(rt->right, bottom);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;

    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    leftBound(root, res);
    bottomBound(root, res);
    rightBound(root, res);

    return res;
}