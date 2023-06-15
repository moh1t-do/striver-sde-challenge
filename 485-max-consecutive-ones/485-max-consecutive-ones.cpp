class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt,res;
        cnt = res = 0;
        
        for(int i=0; i<nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
                res = max(res, cnt);
            }
            else
                cnt = 0;
        }
        return res;
    }
};