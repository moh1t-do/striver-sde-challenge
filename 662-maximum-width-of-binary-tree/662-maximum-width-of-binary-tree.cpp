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
    int widthOfBinaryTree(TreeNode* root) {
        int res = 0;
        if (!root)
        return res;

        queue<pair<TreeNode*, long long>> qu;
        qu.push({root, 0});
        int left, right;
        while(!qu.empty())
        {
            int sz = qu.size();
            int minIdx = qu.front().second;
            for(int i=0; i<sz; i++)
            {
                auto p = qu.front();
                qu.pop();
                TreeNode *q = p.first;
                long long curIdx = p.second - minIdx;

                if (i == 0)
                left = curIdx;
                if (i == sz-1)
                right = curIdx;

                if (q->left)
                qu.push({q->left, 2*curIdx+1});
                if (q->right)
                qu.push({q->right, 2*curIdx+2});
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};