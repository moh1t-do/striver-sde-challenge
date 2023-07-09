class Solution {
public:
    bool isPalin(string &s, int i, int j)
    {
        while(i<=j)
        {
            if (s[i] != s[j]) 
            return false;
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N, -1));
        
        for(int i=0; i<N; i++)
        dp[i][i] = 1;

        int srt, end;
        srt = end = 0;
        for(int i=0; i<N-1; i++)
        {
            if (isPalin(s, i, i+1))
            {
                dp[i][i+1] = 1;
                srt = i;
                end = i+1;   
            }
        }

        int k = 2;
        for(int i=0; i<N-2; i++)
        {
            for(int j=0; j<N-k; j++)
            {
                if (s[j] == s[j+k] && dp[j+1][j+k-1] != -1)
                {
                    dp[j][j+k] = 1;
                    srt = j;
                    end = j+k;
                }
            }
            k++;
        }

        return s.substr(srt, end-srt+1);
    }
};