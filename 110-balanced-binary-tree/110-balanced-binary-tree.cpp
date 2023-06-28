/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int dfsHeight(TreeNode *rt)
    {
        if (!rt) return 0;
        
        int l = dfsHeight(rt->left);
        if (l == -1) return l;

        int r = dfsHeight(rt->right);
        if (r == -1) return r;

        if (abs(l-r) > 1) return -1;

        return (1+ max(l,r));
    }
public:
    bool isBalanced(TreeNode* root) {
        return (dfsHeight(root) != -1);
    }
};