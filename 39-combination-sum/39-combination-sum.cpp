class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void solve(vector<int>& c, int i, int t)
    {
        if (i == c.size())
        {
            if (t == 0)
                ans.push_back(tmp);
            return;
        }
        
        if (c[i] <= t)
        {
            tmp.push_back(c[i]);
            solve(c, i, t-c[i]);
            tmp.pop_back();
        }
        solve(c, i+1, t);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,0 ,target);
        return ans;
    }
};