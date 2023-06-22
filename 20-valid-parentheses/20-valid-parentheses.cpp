class Solution {
public:
    bool isValid(string s) {
        stack<int> stk;
        unordered_map<char,int> mp;
        mp['('] = -1;
        mp['{'] = -2;
        mp['['] = -3;
        mp[')'] = 1;
        mp['}'] = 2;
        mp[']'] = 3;
        
        for(auto &it: s)
        {
            if (mp[it] < 0)
                stk.push(mp[it]);
            else if (stk.empty() || (stk.top()+mp[it])) return false;
            else stk.pop();
        }
        return stk.empty();
    }
};
