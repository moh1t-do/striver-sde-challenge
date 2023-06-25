class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pre(n), suf(n);
        
        for(int i=0; i<n; i++)
        {
            pre[i] = i;
            suf[i] = n-i-1;
        }
        
        stack<int> stk;
        for(int i=0; i<n; i++)
        {
            while(!stk.empty() && heights[stk.top()]>heights[i])
            {
                suf[stk.top()] = i-stk.top()-1;
                stk.pop();
            }
            stk.push(i);
        }
        
        while(!stk.empty()) stk.pop();
        
        for(int i=n-1; i>=0; i--)
        {
            while(!stk.empty() && heights[stk.top()]>heights[i])
            {
                pre[stk.top()] = stk.top()-i-1;
                stk.pop();
            }
            stk.push(i);
        }
        
        int res = 0;
        for(int i=0; i<n; i++)
            res = max(res, (1+pre[i]+suf[i])*heights[i]);
        
        return res;
    }
};