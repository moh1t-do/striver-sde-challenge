#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int, int> ump;
    ump[0] = 1;

    int res, k;
    res = k = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        k ^= arr[i];
        res += ump[k ^ x];
        ump[k]++;
    }
    return res;
}