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
    TreeNode* constructTree(vector<int>& pre, int preS, int preE, vector<int>& in, int inS, int inE, unordered_map<int, int> &mp)
    {
        if (preS > preE || inS > inE)
        return NULL;

        TreeNode *rt = new TreeNode(pre[preS]);
        int ele = mp[rt->val];
        int nele = ele - inS;
        
        rt->left = constructTree(pre, preS+1, preS+nele, in, inS, ele-1, mp);
        rt->right = constructTree(pre, preS+nele+1, preE, in, ele+1, inE, mp);

        return rt;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
        mp[inorder[i]] = i;
        int preStart, preEnd, inStart, inEnd;
        preStart = inStart = 0;
        preEnd = inEnd = preorder.size() - 1;
        return (constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp));

    }
};