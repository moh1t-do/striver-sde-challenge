class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i, j;
        i = 1;
        j = 0;
        
        for(; i<nums.size(); i++)
        {
            if (nums[i] != nums[j])
            {
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};