class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n-1] != nums[n-2]) return nums[n-1];

        int l, h;
        l = 1;
        h = n-2;
        int res = -1;
        while(l<=h)
        {
            int m = l+(m-l)/2;
            if (nums[m] != nums[m-1] && nums[m] != nums[m+1])
            {
                res = m;
                break;
            }

            if (m%2 == 1 && nums[m] == nums[m+1] || m%2 == 0 && nums[m] == nums[m-1]) h = m-1;
            else l = m+1;
        }
        return nums[res];
    }
};