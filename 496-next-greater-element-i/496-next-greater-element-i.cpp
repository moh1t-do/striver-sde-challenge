class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> ump;
        stack<int> stk;
        
        for(int i=0; i<nums2.size(); i++)
        {
            while(!stk.empty() && nums2[i] > stk.top())
            {
                ump[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }
        
        while(!stk.empty())
        {
            ump[stk.top()] = -1;
            stk.pop();
        }
        
        vector<int> ans;
        for(auto &i: nums1)
            ans.push_back(ump[i]);
        return ans;
    }
};