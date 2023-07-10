void calc(string &pat, int M, int lps[])
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> stringMatch(string txt, string pat)
{
    // Write your code here.
    int M = pat.size();
    int N = txt.size();
    vector<int> res;

    int lps[M];
    calc(pat, M, lps);

    int i, j;
    i = j = 0;
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }
        if (j == M)
        {
            res.push_back(i - j + 1);
            j = lps[j - 1];
        }
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}
