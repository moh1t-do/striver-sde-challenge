class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        
        int pre, suf;
        int res = INT_MIN;
        pre = suf = 1;
        for(int i=0; i<n; i++)
        {
            pre *= nums[i];
            suf *= nums[n-i-1];
            res = max(res, max(pre,suf));
            if (pre == 0)
                pre = 1;
            if (suf == 0)
                suf = 1;
        }
        return res;
    }
};