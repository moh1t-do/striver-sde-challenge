vector<int> stringMatch(string txt, string pat)
{
    vector<int> res;

    int d = 256; // No of characters in input
    int q = 101; // Prime number to do mod operation
    int M = pat.length();
    int N = txt.length();

    if (M > N)
    {
        return res;
    }

    int i, j;
    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for txt
    int h = 1;

    for (i = 1; i < M; i++)
        h = (d * h) % q;

    for (i = 0; i < M; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++)
    {
        if (p == t)
        {
            for (j = 0; j < M; j++)
            {
                if (pat[j] != txt[i + j])
                    break;
            }
            if (j == M)
                res.push_back(i + 1);
        }

        if (i < N - M)
        {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            if (t < 0)
                t = t + q;
        }
    }
    return res;
}