class Solution {
public:
    int strStr(string haystack, string needle) {
        string str;
        str = needle+"#"+haystack;

        vector<int> z;
        int i=0;
        while(i<str.size())
        {
            while(i<=needle.size()) 
            {
                z.push_back(0);
                i++;
            }
            int l, r;
            l = r = 0;
            if (str[l] == str[i])
            {
                r = i;
                while(r < str.size() && str[l] == str[r])
                {
                    l++;
                    r++;
                }
            }
            z.push_back(l);
            i++;
        }

        for(int i=0; i<z.size(); i++)
        {
            if (z[i] == needle.size())
            return i-needle.size()-1;
        }
        return -1;
    }
};