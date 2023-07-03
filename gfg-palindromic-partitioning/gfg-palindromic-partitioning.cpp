//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool isPalin(string &str, int i, int j)
    {
        while (i <= j)
        {
            if (str[i++] != str[j--])
                return false;
        }
        return true;
    }

    int solve(string &str, int idx, int n, vector<int> &dp)
    {
        if (idx == n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];

        int res;
        res = 1e9;
        for (int i = idx; i < n; i++)
        {
            if (isPalin(str, idx, i))
            {
                int p = solve(str, i + 1, n, dp);
                res = min(res, 1 + p);
            }
        }
        return dp[idx] = res;
    }

    int palindromicPartition(string str)
    {
        // code here
        int n = str.length();
        vector<int> dp(n + 1, -1);
        return solve(str, 0, n, dp) - 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;
        cout << ob.palindromicPartition(str) << "\n";
    }
    return 0;
}
// } Driver Code Ends