//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int solve(int arr[], int n, int idx, int pre, vector<vector<int>> &dp)
    {
        if (idx == n)
            return 0;

        int p, np;
        p = np = 0;
        if (dp[idx][pre + 1] != -1)
            return dp[idx][pre + 1];
        np = solve(arr, n, idx + 1, pre, dp);
        if (pre == -1 || arr[idx] > arr[pre])
        {
            p = arr[idx] + solve(arr, n, idx + 1, idx, dp);
            return dp[idx][pre + 1] = max(p, np);
        }

        return dp[idx][pre + 1] = np;
    }

    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(arr, n, 0, -1, dp);
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

// } Driver Code Ends