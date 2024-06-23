class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // brute force approach
        //  O(n3)
        int n = nums.size();
        int maxi = INT_MIN;
        // i is the starting index
        for (int i = 0; i < n; ++i)
        {
            // j is the ending index
            for (int j = i; j < n; ++j)
            {
                int sum = 0;
                for (int k = i; k <= j; ++k)
                {
                    // k is for summation
                    sum += nums[k];
                }
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }
};