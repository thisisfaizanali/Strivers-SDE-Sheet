/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        // dp[i] stores length of LIS ending at index i
        // count[i] stores number of LIS with length dp[i] ending at index i
        vector<int> dp(n, 1), count(n, 1);
        int maxLen = 1; // tracks the maximum LIS length in the array

        for (int i = 0; i < n; ++i)
        {
            for (int p = 0; p < i; ++p)
            {
                // if we can extend LIS from p to i AND it gives a longer sequence:
                if (nums[i] > nums[p] && 1 + dp[p] > dp[i])
                {
                    dp[i] = 1 + dp[p];   // update length of LIS ending at i
                    count[i] = count[p]; // inherit count from previous position
                }
                // if extending from p gives same length as current dp[i]:
                else if (nums[i] > nums[p] && 1 + dp[p] == dp[i])
                    count[i] += count[p]; // add ways to reach p to our count
            }

            maxLen = max(maxLen, dp[i]);
        }

        int ans = 0;
        // sum up all counts where LIS length equals maxLen:
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] == maxLen)
                ans += count[i];
        }
        return ans;
    }
};
