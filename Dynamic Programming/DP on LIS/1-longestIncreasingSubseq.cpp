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

// Tabulation :
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // dp[i][p+1] → LIS starting at i with previous index p
                                                              // (p+1) is used to handle p = -1 (no previous element case)

        // Fill table from end towards beginning
        for (int i = n - 1; i >= 0; --i)
        {
            // Iterate through all possible previous indices (-1 means no previous)
            for (int p = -1; p < n; ++p)
            {
                int notTake = dp[i + 1][p + 1]; // skipping current element; (p+1) shift handles -1 index
                int take = 0;
                // Take current element only if it's greater than previous or no previous exists
                if (p == -1 || nums[i] > nums[p])
                    take = 1 + dp[i + 1][i + 1];   // we shift i by +1 because dp table uses +1 for index mapping
                dp[i][p + 1] = max(take, notTake); // take max of both choices
            }
        }
        return dp[0][0]; // dp[0][0] → start at index 0, previous = -1 (shifted by +1)
    }
};

// Space optimization :
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> curr(n + 1, 0), ahead(n + 1, 0); // index shifting (p+1) still applies as above

        // Iterate backward to simulate tabulation using only two arrays
        for (int i = n - 1; i >= 0; --i)
        {
            for (int p = -1; p < n; ++p)
            {
                int notTake = ahead[p + 1]; // skip current, shifted by +1 to handle p = -1
                int take = 0;
                if (p == -1 || nums[i] > nums[p])
                    take = 1 + ahead[i + 1];      // i+1 shift for same reason as in 2D DP
                curr[p + 1] = max(take, notTake); // store best result
            }
            ahead = curr; // move to next iteration
        }
        return ahead[0]; // represents LIS starting from index 0, p = -1 (shifted)
    }
};

// Different way of thinking and Tabulation :
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1); // dp[i] = LIS ending at index i
                              // no index shifting needed here — dp[i] directly represents i-th element

        // For each element, check all previous ones
        for (int i = 0; i < n; ++i)
        {
            for (int p = 0; p < i; ++p)
            {
                // If nums[i] > nums[p], it can extend the increasing subsequence ending at p
                if (nums[i] > nums[p])
                {
                    dp[i] = max(1 + dp[p], dp[i]); // update LIS length for current index
                }
            }
        }
        return *max_element(dp.begin(), dp.end()); // no shifting here; returns the longest subsequence length directly
    }
};
