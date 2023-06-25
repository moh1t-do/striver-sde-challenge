class Solution {
public:
    vector<vector<string>> ans;
    vector<string> tmp;
    void solve(string &s, int j)
    {
        if (j == s.length())
        {
            ans.push_back(tmp);
            return;
        }
        
        for(int i=j; i< s.length(); i++)
        {
            if (isPalin(s,j,i))
            {
                tmp.push_back(s.substr(j,i-j+1));
                solve(s, i+1);
                tmp.pop_back();
            }
        }
    }
    
    bool isPalin(string s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        solve(s, 0);
        return ans;
    }
};