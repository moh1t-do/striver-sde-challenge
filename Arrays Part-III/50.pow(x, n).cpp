#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = abs(n);

        // using binary expo
        while (nn)
        {
            if (nn & 1)
                ans *= x;
            x *= x;
            nn = nn >> 1;
        }
        if (n < 0)
            ans = 1 / ans;

        return ans;
    }
};