class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // without using maps
        // two pointer approach
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] == target)
                return {left, right};
            else if (nums[left] + nums[right] > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return {};
    }
};