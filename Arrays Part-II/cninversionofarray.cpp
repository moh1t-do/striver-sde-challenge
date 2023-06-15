#include <bits/stdc++.h>

long long merge(long long *arr, int l, int m, int h)
{
    int i = l;
    int j = m + 1;

    long long cnt = 0;
    vector<long long> tmp;
    while (i <= m && j <= h)
    {
        if (arr[i] <= arr[j])
        {
            tmp.push_back(arr[i]);
            i++;
        }
        else
        {
            cnt += (m - i + 1);
            tmp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= m)
    {
        tmp.push_back(arr[i++]);
    }
    while (j <= h)
    {
        tmp.push_back(arr[j++]);
    }

    for (int i = l; i <= h; i++)
        arr[i] = tmp[i - l];
    return cnt;
}

long long mergeSort(long long *arr, int l, int h)
{
    long long cnt = 0;
    if (l >= h)
        return cnt;
    int m = l + (h - l) / 2;
    cnt += mergeSort(arr, l, m);
    cnt += mergeSort(arr, m + 1, h);
    cnt += merge(arr, l, m, h);
    return cnt;
}

long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return mergeSort(arr, 0, n - 1);
}