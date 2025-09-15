/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // think of s1 : positives and s2 : negatives
    // problem reduces to finding count of subsets with given difference
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalSum = 0;    // total sum of all elements
        int n = nums.size(); // number of elements
        for (int &x : nums)
            totalSum += x; // compute total sum

        if (target > totalSum) // if target is greater than possible sum, no solution
            return 0;
        if (target < -totalSum) // if target is less than negative total sum, no solution
            return 0;
        if ((totalSum + target) & 1) // (totalSum + target) must be even to form valid subset sum
            return 0;

        int sum = (target + totalSum) / 2; // required subset sum (transformed problem)

        // dp[i][s] = number of ways to make sum 's' using first i elements
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // Base case: sum = 0 can always be formed by taking no elements
        for (int i = 0; i < n; ++i)
            dp[i][0] = 1;

        // Special handling for the first element
        if (nums[0] == 0) // if first element is zero -> can include or exclude (2 ways)
            dp[0][nums[0]] = 2;
        else if (nums[0] <= sum) // if first element <= sum, it can form that sum
            dp[0][nums[0]] = 1;

        // Fill dp table
        for (int i = 1; i < n; ++i)
        {
            for (int s = 0; s <= sum; ++s)
            {
                // pick current element if it's <= current sum
                int pick = (nums[i] <= s) ? dp[i - 1][s - nums[i]] : 0;
                // don't pick current element
                int notPick = dp[i - 1][s];

                // total ways = pick + notPick
                dp[i][s] = pick + notPick;
            }
        }

        return dp[n - 1][sum]; // final answer: ways to make 'sum' using all elements
    }
};
