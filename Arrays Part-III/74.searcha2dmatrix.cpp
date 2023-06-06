#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int l, h, m, n, k;
        k = matrix[0].size();
        n = k * matrix.size();

        l = 0;
        h = n - 1;

        // treat as a 1D array
        while (h >= l)
        {
            m = l + (h - l) / 2;
            int i, j;
            i = m / k;
            j = m % k;
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                l = m + 1;
            else
                h = m - 1;
        }
        return false;
    }
};