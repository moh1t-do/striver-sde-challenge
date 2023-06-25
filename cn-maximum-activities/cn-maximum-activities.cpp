#include <bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &end)
{
    // Write your code here.
    vector<pair<int, int>> vec;
    int n = start.size();
    for (int i = 0; i < n; i++)
        vec.push_back({start[i], end[i]});

    sort(vec.begin(), vec.end(), [](pair<int, int> &x, pair<int, int> &y)
         { return (x.second < y.second); });

    int x, cnt;
    x = -1;
    cnt = 0;

    for (int i = 0; i < n; i++)
        if ((x == -1 || vec[i].first >= x))
        {
            x = vec[i].second;
            cnt++;
        }

    return cnt;
}