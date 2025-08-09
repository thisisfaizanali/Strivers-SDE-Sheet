/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class Solution
{
private:
    int memoization(int index, vector<int> &nums, vector<int> &memo)
    {
        if (index == 0)
            return nums[0]; // Base case: only one house, rob it
        if (index < 0)
            return 0; // Base case: no houses left, no money
        if (memo[index] != -1)
            return memo[index]; // Return already computed result

        int pick = nums[index] + memoization(index - 2, nums, memo); // Rob current house + result from index-2
        int notPick = 0 + memoization(index - 1, nums, memo);        // Skip current house

        memo[index] = max(pick, notPick); // Take maximum of both choices
        return memo[index];
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> memo(n + 1, -1);           // Initialize memo with -1
        return memoization(n - 1, nums, memo); // Start from last house
    }
};

// Tabulation :
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0]; // Base case

        for (int i = 1; i < n; ++i)
        {
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2];   // Add dp[i-2] if exists
            int notPick = dp[i - 1]; // Skip current house

            dp[i] = max(pick, notPick); // Maximize money robbed
        }
        return dp[n - 1]; // Result at last house
    }
};

// Space optimization :
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int prev2 = 0;      // dp[i-2]
        int prev = nums[0]; // dp[i-1]

        for (int i = 1; i < n; ++i)
        {
            int pick = nums[i];
            if (i > 1)
                pick += prev2;  // Add dp[i-2] if applicable
            int notPick = prev; // Skip current house

            int curr = max(pick, notPick); // Max money at current house

            prev2 = prev; // Update dp[i-2]
            prev = curr;  // Update dp[i-1]
        }
        return prev; // Final answer
    }
};
