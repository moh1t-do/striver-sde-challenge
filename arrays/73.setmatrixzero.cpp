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

void setZeroes(vector<vector<int>> &matrix)
{

    int col0 = 1;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {

            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j == 0)
                    col0 = 0;
                else
                    matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
    }

    cout << matrix[0][0] << endl;
    if (matrix[0][0] == 0)
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[0][i] = 0;

    if (col0 == 0)
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
}

void solve()
{
    vector<vector<int>> vec{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    // /INPUT
    setZeroes(vec);
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