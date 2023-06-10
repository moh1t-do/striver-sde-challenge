class Solution {
public:
    bool dfs(vector<int> adj[], vector<int>& vis, vector<int>& path, int i)
    {
        vis[i] = 1;
        path[i] = 1;

        for(auto &x: adj[i])
        {
            if (!vis[x] && dfs(adj, vis, path, x) || path[x] == 1)
                return true;
        }
        path[i] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto &pre: prerequisites)
        adj[pre[1]].push_back(pre[0]);

        vector<int> vis(numCourses);
        vector<int> path(numCourses);

        // cycle detection using dfs
        for(int i=0; i<numCourses; i++)
        {
            if (!vis[i])
            {
                if (dfs(adj, vis, path, i))
                return false;
            }
        }
        return true;
    }
};