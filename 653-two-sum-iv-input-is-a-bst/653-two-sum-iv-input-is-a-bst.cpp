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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,bool> ump;
        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty())
        {
            int sz = qu.size();
            while(sz--)
            {
                TreeNode *tmp = qu.front();
                qu.pop();

                if (ump[k-tmp->val])
                return true;

                ump[tmp->val] = true;

                if (tmp->left)
                qu.push(tmp->left);

                if (tmp->right)
                qu.push(tmp->right);
            }
        }
        return false;
    }
};