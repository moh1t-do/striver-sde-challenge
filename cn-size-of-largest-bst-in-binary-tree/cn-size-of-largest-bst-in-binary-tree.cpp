#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

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
class Node
{
public:
    int maxN, minN, maxS;
    Node(int minN, int maxN, int maxS)
    {
        this->minN = minN;
        this->maxN = maxN;
        this->maxS = maxS;
    }
};

Node solve(TreeNode<int> *rt)
{
    if (!rt)
        return Node(INT_MAX, INT_MIN, 0);

    auto left = solve(rt->left);
    auto right = solve(rt->right);

    if (left.maxN < rt->data && rt->data < right.minN)
        return Node(min(rt->data, left.minN),
                    max(rt->data, right.maxN),
                    left.maxS + right.maxS + 1);

    return Node(INT_MIN, INT_MAX, max(left.maxS, right.maxS));
}

int largestBST(TreeNode<int> *root)
{
    // Write your code here.
    return solve(root).maxS;
}
