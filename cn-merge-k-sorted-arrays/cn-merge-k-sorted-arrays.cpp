#include <bits/stdc++.h>

void merge(vector<int> &x, vector<int> &y)
{
    int i, j, m, n;
    i = j = 0;
    m = x.size();
    n = y.size();
    vector<int> tmp;

    while (i < m && j < n)
    {
        if (x[i] <= y[j])
            tmp.push_back(x[i++]);
        else
            tmp.push_back(y[j++]);
    }

    while (i < m)
        tmp.push_back(x[i++]);
    while (j < n)
        tmp.push_back(y[j++]);

    x.clear();
    x.insert(x.begin(), tmp.begin(), tmp.end());
}

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    for (int i = k - 1; i >= 1; i--)
        merge(kArrays[i - 1], kArrays[i]);
    return kArrays[0];
}
