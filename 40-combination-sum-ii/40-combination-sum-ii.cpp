class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void solve(vector<int>& c, int t, int i)
    {
        if (t == 0)
        {
            ans.push_back(tmp);
            return;
        }
        
        for(int j=i; j<c.size(); j++)
        {
            if (j>i && c[j] == c[j-1])
                continue;
            if (c[j] > t)
            break;
            tmp.push_back(c[j]);
            solve(c, t-c[j], j+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans;
    }
};