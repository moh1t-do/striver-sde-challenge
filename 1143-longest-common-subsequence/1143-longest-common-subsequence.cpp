class Solution {
public:
    int solve(int i, string &t1, int j, string &t2, vector<vector<int>> &dp)
    {
        if (i == t1.length() || j == t2.length()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int p, np1, np2;
        p = np1 = np2 = 0;
        if (t1[i] == t2[j])
        p = 1+solve(i+1, t1, j+1, t2, dp);
        
        np1 = solve(i, t1, j+1, t2, dp);
        np2 = solve(i+1, t1, j, t2, dp);

        return dp[i][j] = max(p, max(np1, np2));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int sz = max(text1.length(), text2.length());
        vector<vector<int>> dp(sz, vector<int>(sz, -1));
        return solve(0, text1, 0, text2, dp);
    }
};