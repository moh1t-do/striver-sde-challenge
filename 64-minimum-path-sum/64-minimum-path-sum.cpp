class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n,0);
        for(int i=0; i<m; i++)
        {
            vector<int> cur(n,0);
            for(int j=0; j<n; j++)
            {
                if (i == 0 && j == 0) cur[j] = grid[i][j];
                else
                {
                    int r, b;
                    r = b = INT_MAX;
                    if (i>0) r = dp[j];
                    if (j>0) b = cur[j-1];
                    cur[j] = grid[i][j] + min(r,b);
                } 
            }
            dp = cur;
        }
        return dp[n-1];
    }
};