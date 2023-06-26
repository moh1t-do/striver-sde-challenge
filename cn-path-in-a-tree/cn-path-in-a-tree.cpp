#include <bits/stdc++.h>
/*
    template <typename T = int>
    class TreeNode
    {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if (left != NULL)
            {
                delete left;
            }
            if (right != NULL)
            {
                delete right;
            }
        }
    };
*/

bool findPath(TreeNode<int> *rt, vector<int> &res, int x)
{
    if (rt == NULL)
        return false;

    res.push_back(rt->data);
    if (rt->data == x)
        return true;

    if (findPath(rt->left, res, x) || findPath(rt->right, res, x))
        return true;
    else
        res.pop_back();

    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> res;
    findPath(root, res, x);
    return res;
}
