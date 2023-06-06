#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int c1, c2, e1, e2;
        c1 = c2 = 0;

        // voting algo mod
        for (int i = 0; i < nums.size(); i++)
        {
            if (c1 == 0 && nums[i] != e2)
            {
                c1 = 1;
                e1 = nums[i];
            }
            else if (c2 == 0 && nums[i] != e1)
            {
                c2 = 1;
                e2 = nums[i];
            }
            else if (nums[i] == e1)
                c1++;
            else if (nums[i] == e2)
                c2++;
            else
            {
                c1--;
                c2--;
            }
        }
        c1 = c2 = 0;
        for (auto &i : nums)
        {
            if (i == e1)
                c1++;
            else if (i == e2)
                c2++;
        }
        if (c1 > nums.size() / 3)
            ans.push_back(e1);
        if (c2 > nums.size() / 3)
            ans.push_back(e2);
        return ans;
    }
};