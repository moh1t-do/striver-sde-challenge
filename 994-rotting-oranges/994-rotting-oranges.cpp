class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;
        map<pair<int,int>, bool> vis;

        int fresh, m, n, res;
        fresh = 0;
        res = -1;
        m = grid.size();
        n = grid[0].size();

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if (grid[i][j] == 1)
                // counting fresh oranges
                fresh++;
                else if (grid[i][j] == 2)
                {
                    vis[{i,j}] = true;
                    qu.push({i,j});
                }
            }
        }

        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,-1,0,1};

        // dfs
        while(!qu.empty())
        {
            int sz = qu.size();
            while(sz--)
            {
                auto p = qu.front();
                qu.pop();

                int row = p.first;
                int col = p.second;

                for(int i=0; i<4; i++)
                {
                    int x = row + dr[i];
                    int y = col + dc[i];
                    auto tmp = make_pair(x,y);
                    if (x>=0 && x<m && y>=0 && y<n && grid[x][y] != 0 && !vis[tmp])
                    {
                        // updating fresh oranges
                        fresh--;
                        vis[tmp] = true;
                        qu.push(tmp);
                    }
                }

            }
            res++;
        }

        if (fresh > 0)
        return -1;
        else
        return max(res,0);
    }
};