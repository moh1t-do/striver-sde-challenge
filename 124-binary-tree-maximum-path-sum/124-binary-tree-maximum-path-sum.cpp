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
    int solve(TreeNode *n, int &mx)
    {
        if (n==NULL)
            return 0;
        int l = max(0, solve(n->left, mx));
        int r = max(0, solve(n->right, mx));
        mx = max(mx, (l+r+n->val));
        return (max(l,r) + n->val);
    }
    
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        solve(root, mx);
        return mx;
    }
};