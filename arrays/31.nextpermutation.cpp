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

// algorithms next_permutation generates next permutation
void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}

void solve()
{
    vector<int> nums{1, 2, 3};
    // /INPUT
    nextPermutation(nums);
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