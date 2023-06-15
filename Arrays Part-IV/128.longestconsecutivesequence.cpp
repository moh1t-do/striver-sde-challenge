class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        unordered_set<int> us;
        for (auto &i : nums)
            us.insert(i);
        int res = INT_MIN;
        for (auto &i : us)
        {
            if (!us.count(i - 1))
            {
                int cnt, curr;
                cnt = 1;
                curr = i;
                while (us.count(curr + 1))
                {
                    curr++;
                    cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};