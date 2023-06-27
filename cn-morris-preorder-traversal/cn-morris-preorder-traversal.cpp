#include <bits/stdc++.h>
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> preorder;
    TreeNode *cur = root;

    while (cur)
    {
        if (!cur->left)
        {
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else
        {
            TreeNode *pre = cur->left;
            while (pre->right && pre->right != cur)
                pre = pre->right;

            if (!pre->right)
            {
                pre->right = cur;
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else
            {
                pre->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}