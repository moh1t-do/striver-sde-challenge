#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &num1, int m, vector<int> &num2, int n)
    {
        // three pointer
        int i, j, k;
        i = m - 1;
        j = n - 1;
        k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (num1[i] > num2[j])
            {
                num1[k] = num1[i];
                k--;
                i--;
            }
            else
            {
                num1[k] = num2[j];
                k--;
                j--;
            }
        }
        for (int i = k; j >= 0; i--)
        {
            num1[i] = num2[k];
            j--;
            k--;
        }
    }
};