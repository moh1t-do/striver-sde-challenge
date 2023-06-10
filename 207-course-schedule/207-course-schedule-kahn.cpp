class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto &pre: prerequisites)
        adj[pre[1]].push_back(pre[0]);

        vector<int> indeg(numCourses);
        for(int i=0; i<numCourses; i++)
        {
            for(auto &i: adj[i])
            indeg[i]++;
        }

        queue<int> qu;
        for(int i=0; i<numCourses; i++)
        {
            if (indeg[i] == 0)
            qu.push(i);
        }
        
        // kahn's algorithm
        int cnt = 0;
        while(!qu.empty())
        {
            int sz = qu.size();
            while(sz--)
            {
                int x = qu.front();
                cnt++;
                qu.pop();
                for(auto &i: adj[x])
                {
                    indeg[i]--;
                    if (indeg[i] == 0)
                    qu.push(i);
                }
            }
        }

        return (cnt == numCourses);
    }
};