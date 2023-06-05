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

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> pascal;
    vector<int> tmp;
    tmp.push_back(1);
    pascal.push_back(tmp);

    if (numRows == 1)
        return pascal;
    tmp.push_back(1);
    pascal.push_back(tmp);

    if (numRows == 2)
        return pascal;

    tmp.clear();
    for (int i = 3; i <= numRows; i++)
    {
        tmp.push_back(1);
        for (int j = 1; j < i - 1; j++)
        {
            tmp.push_back(pascal[i - 2][j - 1] + pascal[i - 2][j]);
        }
        tmp.push_back(1);
        pascal.push_back(tmp);
        tmp.clear();
    }
    return pascal;
}

void solve()
{
    int n = 5;
    // /INPUT
    generate(n);
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