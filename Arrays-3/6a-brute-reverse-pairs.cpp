class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        // pair(i,j) such that:
        //  0 <= i < j < nums.length and
        //  nums[i] > 2 * nums[j]
        long long n = nums.size();
        int count = 0;
        for (long long i = 0; i < n; ++i)
        {
            for (long long j = i + 1; j < n; ++j)
            {
                if (nums[i] > 2 * nums[j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};