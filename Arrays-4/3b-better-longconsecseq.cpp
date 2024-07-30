class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        int longest = 1;
        int lastsmallest = -1;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] - 1 == lastsmallest)
            {
                count++;
                lastsmallest = nums[i];
            }
            else if (nums[i] != lastsmallest)
            {
                count = 1;
                lastsmallest = nums[i];
            }
            longest = max(longest, count);
        }
        return longest;
    }
};