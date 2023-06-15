class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int i, j, res;
        i = j = 0;
        res = INT_MIN;
        unordered_map<char, int> mp;
        if (s.length() == 0)
            return 0;

        while (j < s.length())
        {
            mp[s[j]]++;
            if (j - i + 1 == mp.size())
            {
                res = max(res, j - i + 1);
                j++;
            }
            else
            {
                while (j - i + 1 != mp.size())
                {
                    char x = s[i];
                    if (mp[x] == 1)
                        mp.erase(x);
                    else
                        mp[x]--;
                    i++;
                }
                j++;
            }
        }
        return res;
    }
};