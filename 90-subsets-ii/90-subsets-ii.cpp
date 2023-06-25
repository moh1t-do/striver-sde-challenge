class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    
    void solve(vector<int> &v, int i)
    {
        ans.push_back(tmp);
        for(int j=i; j<v.size(); j++)
        {
            if (j>i && v[j] == v[j-1])
                continue;
            tmp.push_back(v[j]);
            solve(v, j+1);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(nums, 0);
        return ans;
    }
};