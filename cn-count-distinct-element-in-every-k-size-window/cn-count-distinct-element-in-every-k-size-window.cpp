#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k)
{
    // Write your code here
    unordered_map<int, int> ump;
    vector<int> res;
    int i, j;
    i = j = 0;
    while (j < arr.size())
    {
        ump[arr[j]]++;
        if (j - i + 1 < k)
            j++;
        else
        {
            res.push_back(ump.size());
            if (ump[arr[i]] == 1)
                ump.erase(arr[i]);
            else
                ump[arr[i]]--;
            i++;
            j++;
        }
    }
    return res;
}
