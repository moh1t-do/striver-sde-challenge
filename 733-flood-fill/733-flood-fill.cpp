class Solution {
public:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, -1, 0, 1};
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n, int c)
    {
        int x = grid[i][j];
        grid[i][j] = c;

        for(int k=0; k<4; k++)
        {
            int row = drow[k] + i;
            int col = dcol[k] + j;
            if (row >= 0 && row <= m && col >= 0 && col <= n && grid[row][col] != c && grid[row][col] == x)
            dfs(grid, row, col, m, n, c);
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int res = 0;
        vector<vector<int>> img = image;
        dfs(img, sr, sc, m-1, n-1, color);
        return img;
    }
};