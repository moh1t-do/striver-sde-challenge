class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> a;
        for (int i = 0; i < nums.size(); i++)
        {
            if (a.find(target - nums[i]) != a.end())
            {
                return {i, a[target - nums[i]]};
            }
            a[nums[i]] = i;
        }

        return {};
    }
};