class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        // O(n2)
        // A better appproach
        // Mene pahle ya{hi socha tha
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += nums[j];
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};