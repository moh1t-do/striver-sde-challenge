class Solution {
private:
    vector<vector<int>> res;
    
    void generateP(vector<int> &nums, int idx, int n)
    {
        if (idx == n)
        {
            res.push_back(nums);
            return;
        }
        
        for(int i=idx; i<n; i++)
        {
            swap(nums[idx], nums[i]);
            generateP(nums, idx+1, n);
            swap(nums[idx], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        generateP(nums, 0, nums.size());
        return res;
    }
};