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
    int res;
    void small(TreeNode *rt, int &k)
    {
        if(rt)
        {
            small(rt->left, k);
            k--;
            if (k == 0)
            {
                res = rt->val;
                return;
            }
            small(rt->right, k);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        small(root, k);
        return res;
    }
};