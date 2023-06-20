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
    TreeNode* consTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd,  unordered_map<int,int> &hsh)
    {
        if (inStart > inEnd || postStart > postEnd)
        return NULL;
        TreeNode *rt = new TreeNode(postorder[postEnd]);
        int ele = hsh[rt->val];
        int nele = ele - inStart;

        rt->left = consTree(postorder, postStart, postStart+nele-1, inorder, inStart, ele-1, hsh);
        rt->right = consTree(postorder, postStart+nele, postEnd-1, inorder, ele+1, inEnd, hsh);
        return rt;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        // start and end positions
        int inStart, inEnd, postStart, postEnd;
        inStart = postStart = 0;
        inEnd = inorder.size() - 1;
        postEnd = postorder.size() - 1;

        // hsh map for inoder
        unordered_map<int,int> hsh;
        for(int i=inStart; i<=inEnd; i++)
        hsh[inorder[i]] = i;
        return (consTree(postorder, postStart, postEnd, inorder, inStart, inEnd, hsh));
    }
};