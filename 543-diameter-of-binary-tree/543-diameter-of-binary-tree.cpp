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
public:
    int findHeight(TreeNode* n, int &mx)
    {
        if (n == NULL)
            return 0;
        int l = findHeight(n->left, mx);
        int h = findHeight(n->right, mx);
        // find maximum
        mx = max(mx, (l+h));
        return(1+max(l,h));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        (findHeight(root, d));
        return d;
    }
};