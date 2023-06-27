#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return {};
    vector<int> preorder, inorder, postorder;

    stack<pair<BinaryTreeNode<int> *, int>> stk;
    stk.push({root, 1});

    while (!stk.empty())
    {
        auto p = stk.top();
        stk.pop();

        if (p.second == 1)
        {
            preorder.push_back(p.first->data);
            p.second++;
            stk.push(p);

            if (p.first->left)
                stk.push({p.first->left, 1});
        }
        else if (p.second == 2)
        {
            inorder.push_back(p.first->data);
            p.second++;
            stk.push(p);

            if (p.first->right)
                stk.push({p.first->right, 1});
        }
        else
        {
            postorder.push_back(p.first->data);
        }
    }

    return {inorder, preorder, postorder};
}