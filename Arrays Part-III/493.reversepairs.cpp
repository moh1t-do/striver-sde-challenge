class Solution
{
private:
    int mergeSort(vector<int> &nums, int l, int h)
    {
        int res = 0;
        if (l >= h)
            return res;

        int m = l + (h - l) / 2;
        res += mergeSort(nums, l, m);
        res += mergeSort(nums, m + 1, h);
        res += countPairs(nums, l, m, h);
        merge(nums, l, m, h);

        return res;
    }

    int countPairs(vector<int> &nums, int l, int m, int h)
    {
        int res = 0;
        int j = m + 1;
        long long ll = 1;
        for (int i = l; i <= m; i++)
        {
            while (j <= h && nums[i] / 2.0 > nums[j])
                j++;
            res += (j - (m + 1));
        }

        return res;
    }

    void merge(vector<int> &nums, int l, int m, int h)
    {
        int i, j;
        i = l;
        j = m + 1;

        vector<int> tmp;
        while (i <= m && j <= h)
        {
            if (nums[i] <= nums[j])
                tmp.push_back(nums[i++]);
            else
                tmp.push_back(nums[j++]);
        }

        while (i <= m)
        {
            tmp.push_back(nums[i++]);
        }
        while (j <= h)
        {
            tmp.push_back(nums[j++]);
        }

        for (int i = l; i <= h; i++)
            nums[i] = tmp[i - l];
    }

public:
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};