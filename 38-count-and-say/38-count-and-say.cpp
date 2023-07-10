class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        if (n == 2) return "11";
        string str = "11";

        for(int i=3; i<=n; i++)
        {
            string tmp;
            str.push_back('#');
            int cnt = 1;
            for(int j=1; j<str.size(); j++)
            {
                if (str[j] == str[j-1])
                cnt++;
                else
                {
                    tmp.append(to_string(cnt));
                    tmp.push_back(str[j-1]);
                    cnt = 1;
                }
            }
            str = tmp;
        }
        return str;
    }
};