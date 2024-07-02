class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // if we sort this array
        // then the repeated numbers will be adjacent
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == nums[i + 1])
            {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};