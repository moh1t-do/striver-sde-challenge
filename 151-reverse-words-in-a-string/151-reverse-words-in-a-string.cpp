class Solution {
public:
    string reverseWords(string s) {
        s.push_back(' ');
        string t, res;
        t=res="";
        for(auto &i: s)
        {
            if(i == ' ' && t.length() > 0)
            {
                reverse(t.begin(),t.end());
                res.append(t);
                res.push_back(' ');
                t = "";
            }
            else if (i != ' ')
                t.push_back(i);
        }
        res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};