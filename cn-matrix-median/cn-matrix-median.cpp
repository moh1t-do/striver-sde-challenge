int helper(vector<int> &vec, int mid)
{
    int l, h;
    l = 0;
    h = vec.size() - 1;

    while (l <= h)
    {
        int md = l + (h - l) / 2;
        if (vec[md] <= mid)
            l = md + 1;
        else
            h = md - 1;
    }
    return l;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int l, h, m, n;
    l = 1;
    h = 1e9;
    m = matrix.size();
    n = matrix[0].size();
    int ele = (m * n) / 2;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int cnt = 0;
        for (int i = 0; i < m; i++)
            cnt += helper(matrix[i], mid);

        if (cnt <= ele)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return l;
}