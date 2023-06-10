#include<bits/stdc++.h>
bool dfs(vector<vector<int>>& adj, vector<int>& vis, int cur, int par)
{
    vis[cur] = 1;
    for(auto &i: adj[cur])
    {
        if (!vis[i])
        {
            if (dfs(adj, vis, i, cur))
            return true;
        }
        else if (i != par)
        return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0);
    for (auto &i : edges) {
      adj[i[0]].push_back(i[1]);
      adj[i[1]].push_back(i[0]);
    }

    for(int i=1; i<=n; i++)
    {
        if (!vis[i] && dfs(adj, vis, i, -1))
        return "Yes";
    }
    return "No";
}
