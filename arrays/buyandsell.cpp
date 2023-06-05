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

int maxProfit(vector<int> &prices)
{
    int mn = INT_MAX;
    int rs = INT_MIN;
    for (auto &i : prices)
    {
        mn = min(mn, i);
        rs = max(rs, i - mn);
    }
    return rs;
}

void solve()
{
    vector<int> prices{7, 1, 5, 3, 6, 4};
    // /INPUT
    cout << maxProfit(prices) << endl;
    ;
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