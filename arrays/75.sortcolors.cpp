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

// 0 - l-1   sorted
// l - m-1   sorted
// m - h     unsorted
// h+1 - n-1 sorted

// dutch national flag
void sortColors(vector<int> &v)
{
    int l, m, h;
    l = m = 0;
    h = v.size() - 1;

    while (m <= h)
    {
        if (v[m] == 0)
        {
            swap(v[m], v[l]);
            m++;
            l++;
        }
        else if (v[m] == 1)
        {
            m++;
        }
        else
        {
            swap(v[m], v[h]);
            h--;
        }
    }
}

void solve()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    // /INPUT
    sortColors(nums);
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