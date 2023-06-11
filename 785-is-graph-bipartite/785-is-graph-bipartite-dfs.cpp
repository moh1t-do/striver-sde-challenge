class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& col, int ver, int c)
    {
        col[ver] = ~c;
        for(auto &i: graph[ver])
        {
            if (col[i] == -1 && !dfs(graph, col, i, col[ver]))
                    return false;
            else if (col[i] == col[ver])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int m = graph.size();
        int n = graph[0].size();

        vector<int> col(m, -1);
        
        // for connected components
        for(int i=0; i<m; i++)
        {
            if(col[i] == -1 && !dfs(graph, col, i, 0))
            return false;
        }
        return true;
    }
};