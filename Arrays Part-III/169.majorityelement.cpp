#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt, res;
        cnt = 0;

        // voting algorithm
        for (int i = 0; i < nums.size(); i++)
        {
            if (cnt == 0)
                res = nums[i];
            if (nums[i] == res)
                cnt++;
            else
                cnt--;
        }
        return res;
    }
};