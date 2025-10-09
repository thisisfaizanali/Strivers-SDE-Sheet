/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization : O(n²) time complexity
// So DP is not the optimal solution:
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();

        // dp[index][previousIndex+1] stores the LIS from index onwards
        // previousIndex ranges from -1 to n-1, so we shift by +1 for array indexing
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        // Start from index 0 with no previous element (-1)
        return solve(0, -1, nums, dp);
    }

private:
    int solve(int index, int previousIndex, vector<int> &nums, vector<vector<int>> &dp)
    {
        // Base case: reached end of array
        if (index == nums.size())
            return 0;

        if (dp[index][previousIndex + 1] != -1)
            return dp[index][previousIndex + 1];

        // Option 1: Don't pick current element, move to next
        int notPick = solve(index + 1, previousIndex, nums, dp);

        // Option 2: Pick current element (if valid)
        int pick = 0;
        // Can pick if: no previous element OR current > previous (INCREASING)
        if (previousIndex == -1 || nums[index] > nums[previousIndex])
        {
            // Pick current element: add 1 to length and update previousIndex to current index
            pick = 1 + solve(index + 1, index, nums, dp);
        }

        return dp[index][previousIndex + 1] = max(notPick, pick);
    }
};
