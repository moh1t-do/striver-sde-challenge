#include <bits/stdc++.h>
int findMinimumCoins(int amt)
{
    // Write your code here
    vector<int> ch = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int cnt = 0;
    for (int i = 8; i >= 0; i--)
    {
        while (amt >= ch[i])
        {
            cnt++;
            amt -= ch[i];
        }
    }
    return cnt;
}
