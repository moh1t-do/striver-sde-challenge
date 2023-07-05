class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l, h, m;
        l = 0;
        h = nums.size()-1;
        
        while(h-l > 1)
        {
            m = (l+h) >> 1;
            if (nums[m] == target)
                return m;
            
            if (nums[l] <= nums[m])
            {
                if (nums[l] <= target && target < nums[m])
                    h=m-1;
                else
                    l=m+1;
            }
            else
            {
                if (nums[h] >= target && target > nums[m])
                    l=m+1;
                else
                    h=m-1;
            }
        }
        if (nums[l] == target)
            return l;
        else if (nums[h] == target)
            return h;
        return -1;
    }
};