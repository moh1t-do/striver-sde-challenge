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
    void preorder(TreeNode* r)
    {
        if (r == NULL)
            return;
        res.push_back(r->val);
        preorder(r->left);
        preorder(r->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }
};