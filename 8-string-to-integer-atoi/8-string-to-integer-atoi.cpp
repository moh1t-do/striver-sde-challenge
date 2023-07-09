class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        double num = 0;
        int i = 0;

        // skip whitespaces
        while(s[i] == ' ') i++;

        // check for sign
        bool pos = s[i] == '+';
        bool neg = s[i] == '-';
        pos == true ? i++ : i;
        neg == true ? i++ : i;

        // formation of number
        while(i<len && s[i] >= '0' && s[i] <= '9')
        {
            num = num*10 + (s[i]-'0');
            i++;
        }
        num = neg ? -num : num;

        // check for out of bounds
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;

        return int(num);
    }
};