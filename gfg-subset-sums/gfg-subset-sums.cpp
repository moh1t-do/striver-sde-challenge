//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    vector<int> res;

public:
    void solve(vector<int> &arr, int n, int s)
    {
        if (n == -1)
        {
            res.push_back(s);
            return;
        }
        solve(arr, n - 1, s + arr[n]);
        solve(arr, n - 1, s);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        solve(arr, N - 1, 0);
        return res;
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans)
        {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends