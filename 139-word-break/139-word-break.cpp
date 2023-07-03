class Solution {
public:
    bool solve(string &s, unordered_map<string, bool> &ump, int idx, vector<int> &dp)
    {
        if (idx == s.length()) return true;

        bool res;
        res = false;
        for(int i=idx; i<s.length(); i++)
        {
            string str = s.substr(idx, i-idx+1);
            if (ump[str])
            {
                if (dp[idx] != -1) return dp[idx];
                bool p = solve(s, ump, i+1, dp);
                res = res || p;
            }
        }

        return dp[idx] = res;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> ump;
        for(auto &it: wordDict) ump[it] = true;
        vector<int> dp(s.length(), -1);
        return solve(s, ump, 0, dp);
    }
};