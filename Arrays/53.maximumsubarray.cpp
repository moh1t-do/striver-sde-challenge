#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

#define F first
#define S second
#define B begin()
#define E end()
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define pi pair<int, int>
#define PB push_back
#define POP pop_back
#define MP make_pair
#define LL long long int
#define line "\n"

int maxSubArray(vector<int> &nums)
{
    int lmax, gmax;
    lmax = 0;
    gmax = INT_MIN;

    for (auto &num : nums)
    {
        // is the current number is big or the sum of is big
        lmax = max(num, lmax + num);
        gmax = max(gmax, lmax);
    }
    return gmax;
}

void solve()
{
    vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // /INPUT
    maxSubArray(vec);
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}