#include <bits/stdc++.h>
using ll = long long int;

bool helper(int n, int m, vector<int> &time, ll t)
{
    ll cnt, nt;
    cnt = nt = 0;
    for (int i = 0; i < m; i++)
    {
        if (nt + time[i] > t)
        {
            cnt++;
            nt = time[i];
            if (nt > t)
                return false;
        }
        else
            nt += time[i];
    }

    return (cnt < n);
}

long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.

    ll l, h, res;
    l = res = 0;

    for (auto &it : time)
        h += it;

    while (l <= h)
    {
        ll mid = l + (h - l) / 2;
        if (helper(n, m, time, mid))
        {
            res = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}