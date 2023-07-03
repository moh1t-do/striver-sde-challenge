class Solution {
public:
    int solve(vector<int>& coins, int amt, vector<int>& dp)
    {
        if (amt == 0) return 0;
        if (amt < 0) return INT_MAX;
        if (dp[amt] != -1) return dp[amt];
        int mn = INT_MAX;
        for(int i=0; i<coins.size(); i++)
        {
            int res = solve(coins, amt-coins[i], dp);
            if (res != INT_MAX) mn = min(mn, res+1); 
        }
        return dp[amt] = mn;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int res = solve(coins, amount, dp);

        return ((res == INT_MAX) ? -1 : res);
    }
};