#include<bits/stdc++.h>
bool bfs(vector<vector<int>>& adj, vector<int>& vis, int src)
{
    queue<pair<int,int>> qu;
    qu.push({src,-1});
    vis[src] = 1;

    while(!qu.empty())
    {
        int sz = qu.size();
        while (sz--)
        {
            auto p = qu.front();
            qu.pop();
            int cur = p.first;
            int par = p.second;

            for (auto &i : adj[cur])
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    qu.push({i, cur});
                } else if (i != par)
                  return true;
            }
        }
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
        if (!vis[i] && bfs(adj, vis, i))
        return "Yes";
    }
    return "No";
}
