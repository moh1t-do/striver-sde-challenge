class Solution {
public:
    int solve(int i, string &w1, int j, string &w2, vector<vector<int>> &dp)
    {
        if (i == -1 || j == -1)
        {
            if (j != -1) return j+1;
            return i+1;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (w1[i] == w2[j]) return dp[i][j] = solve(i-1, w1, j-1, w2, dp);
        
        int l1, l2, l3;
        l1 = solve(i, w1, j-1, w2, dp);
        l2 = solve(i-1, w1, j, w2, dp);
        l3 = solve(i-1, w1, j-1, w2, dp);
        
        return dp[i][j] = 1 + min(l1, min(l2, l3));
    }
    int minDistance(string word1, string word2) {
        int n = max(word1.length(), word2.length());
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(word1.length()-1, word1, word2.length()-1, word2, dp);
    }
};