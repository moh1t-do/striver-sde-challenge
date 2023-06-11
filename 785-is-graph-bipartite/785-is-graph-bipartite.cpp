class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& col, int ver)
    {
        queue<int> qu;
        qu.push(ver);
        col[ver] = 1;

        while(!qu.empty())
        {
            int sz = qu.size();
            while(sz--)
            {
                auto cur = qu.front();
                qu.pop();

                for(auto &i: graph[cur])
                {
                    if (col[i] == -1)
                    {
                        col[i] = ~col[cur];
                        qu.push(i);
                    }
                    else if (col[i] == col[cur])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        int n = graph[0].size();

        vector<int> col(m, -1);
        for(int i=0; i<m; i++)
        {
            if(col[i] == -1 && !dfs(graph, col, i))
            return false;
        }
        return true;
    }
};