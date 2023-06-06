#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // sort
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int n = intervals.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && ans.back()[1] >= intervals[i][0])
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};