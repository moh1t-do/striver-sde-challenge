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

    bool isValid(TreeNode *rt, long long mn, long long mx)
    {
        if (!rt)
        return true;
        bool k = rt->val > mn && rt->val < mx;
        bool left = isValid(rt->left, mn, rt->val);
        bool right = isValid(rt->right, rt->val, mx);
        cout << k << left << right << endl;
        if ((k && left && right) == false)
        return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long mn, mx;
        mn = LLONG_MIN;
        mx = LLONG_MAX;
        return isValid(root,mn,mx);
    }
};