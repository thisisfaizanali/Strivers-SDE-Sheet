class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int index = -1;
        // find the breakpoint
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }
        // if no break points max lex arrangement
        // we have to return in ascending order
        if (index == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        // after finding the break point swap a[i]
        // with element just greater than a[i]
        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }
        // reverseing the right half
        reverse(nums.begin() + index + 1, nums.end());
    }
};