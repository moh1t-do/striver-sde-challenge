class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n)
    {
        grid[i][j] = '0';

        if (i>0 && grid[i-1][j] == '1')
        dfs(grid, i-1, j, m, n);
        if (i<m && grid[i+1][j] == '1')
        dfs(grid, i+1, j, m, n);
        if (j>0 && grid[i][j-1] == '1')
        dfs(grid, i, j-1, m, n);
        if (j<n && grid[i][j+1] == '1')
        dfs(grid, i, j+1, m, n);

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m, n;
        m = grid.size();
        n = grid[0].size();

        int res = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, m-1, n-1);
                    res++;
                }
            }
        }
        return res;
    }
};