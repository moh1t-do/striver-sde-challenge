class Solution
{
    private:
    void dfs(vector<int> adj[], vector<int> &vis, stack<int> &s, int ele)
    {
        vis[ele] = 1;
        for(auto &nd: adj[ele])
        {
            if (!vis[nd])
            dfs(adj, vis, s, nd);
        }
        s.push(ele);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V);
	    stack<int> stk;
	    for(int i=0; i<V; i++)
	    {
	        if (!vis[i])
	        dfs(adj, vis, stk, i);
	    }
	    
	    vector<int> res;
	    while(!stk.empty())
	    {
	        res.push_back(stk.top());
	        stk.pop();
	    }
	    return res;
	}
};