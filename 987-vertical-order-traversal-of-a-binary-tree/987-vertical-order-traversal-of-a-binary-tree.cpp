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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        vector<vector<int>> res;
        queue<pair<TreeNode*, pair<int,int>>> qu;
        if (root == NULL)
            return res;
        qu.push({root,{0,0}});
        
        while(!qu.empty())
        {
            auto p = qu.front();
            qu.pop();
            TreeNode *q = p.first;
            
            int x,y;
            x = p.second.first;
            y = p.second.second;
            nodes[x][y].insert({q->val});
            if (q->left)
            {
                qu.push({q->left,{x-1, y+1}});
            }
            if (q->right)
            {
                qu.push({q->right,{x+1, y+1}});
            }
        }
        for(auto &i: nodes)
        {
            vector<int> col;
            cout << i.first << " ";
            for(auto &j: i.second)
            {
                col.insert(col.end(), j.second.begin(), j.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};