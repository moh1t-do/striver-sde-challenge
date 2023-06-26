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
    vector<int> res;
    void solve(TreeNode* r)
    {
        if (r == NULL)
            return;
        solve(r->left);
        res.push_back(r->val);
        solve(r->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return res;
    }
};