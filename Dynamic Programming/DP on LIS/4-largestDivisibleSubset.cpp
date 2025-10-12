/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();

        // sorting ensures we only check divisibility with smaller elements
        sort(nums.begin(), nums.end());

        // dp[i] = length of longest divisible subset ending at index i
        // hash[i] = previous index in the subset chain (for backtracking)
        vector<int> dp(n, 1), hash(n);
        int lastIndex = 0, maxLen = 1;

        for (int i = 0; i < n; ++i)
        {
            hash[i] = i; // initially points to itself (no previous element)

            for (int p = 0; p < i; ++p)
            {
                // if nums[i] divisible by nums[p] and gives longer subset
                if (nums[i] % nums[p] == 0 && 1 + dp[p] > dp[i])
                {
                    dp[i] = 1 + dp[p]; // extend the subset ending at p
                    hash[i] = p;       // track previous index for reconstruction
                }
            }

            // track where the maximum length subset ends
            if (maxLen < dp[i])
            {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        // backtrack from lastIndex using hash array to build result
        vector<int> ans;
        ans.emplace_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            ans.emplace_back(nums[lastIndex]);
        }

        // result built in reverse, so reverse it back
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
