//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int solve(int arr[], int i, int j)
    {
        if (i == j)
            return 0;

        int mn = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int m = arr[i - 1] * arr[k] * arr[j] + solve(arr, i, k) + solve(arr, k + 1, j);
            mn = min(mn, m);
        }
        return mn;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return solve(arr, 1, N - 1);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends