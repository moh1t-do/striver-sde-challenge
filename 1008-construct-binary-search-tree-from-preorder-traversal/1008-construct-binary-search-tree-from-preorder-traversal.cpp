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
    TreeNode *createTree(vector<int>& preorder, int i, int n)
    {
        if (i > n)
        return NULL;
        int j = i+1;
        
        for(; (j<=n && preorder[j] < preorder[i]); j++);

        TreeNode *rt = new TreeNode(preorder[i], createTree(preorder, i+1, j-1),
        createTree(preorder, j, n));

        return rt;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return createTree(preorder, 0, preorder.size()-1);
    }
};