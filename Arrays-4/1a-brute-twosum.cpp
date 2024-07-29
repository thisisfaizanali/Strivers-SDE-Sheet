class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        int indx1, indx2;
        for (long long i = 0; i < n; ++i)
        {
            for (long long j = i + 1; j < n; ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    indx1 = i;
                    indx2 = j;
                    break;
                }
            }
        }
        return {indx1, indx2};
    }
};