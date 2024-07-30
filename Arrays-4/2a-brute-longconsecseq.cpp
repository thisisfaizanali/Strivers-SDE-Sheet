class Solution
{
public:
    bool linearsearch(vector<int> &nums, int x)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == x)
                return true;
        }
        return false;
    }
    int longestConsecutive(vector<int> &nums)
    {
        int n = nums.size();
        int longest = 1;
        int x;
        for (int i = 0; i < n; ++i)
        {
            x = nums[i];
            int count = 1;
            while (linearsearch(nums, x + 1) == true)
            {
                x = x + 1;
                count++;
            }
            longest = max(longest, count);
        }
        return longest;
    }
};