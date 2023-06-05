#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int sz = matrix.size();

        // transpose
        for (int i = 0; i < sz; i++)
            for (int j = i; j < sz; j++)
                swap(matrix[i][j], matrix[j][i]);

        // reverse
        for (auto &row : matrix)
            reverse(row.begin(), row.end());
    }
};