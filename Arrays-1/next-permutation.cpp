class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        // step1 first i need to find the breakpoint
        int index = -1;
        for (int i = n - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                index = i;
                break;
            }
        }
        // step 2 if no breakpoint means sort in ascending order and return
        if (index == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        // step 3 finding element just greater than nums[index] and swap
        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] > nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }
        // step 4 sort the rhs
        sort(nums.begin() + index + 1, nums.end());
    }
};