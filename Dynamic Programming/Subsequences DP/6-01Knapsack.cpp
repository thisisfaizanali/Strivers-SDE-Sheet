/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class Solution
{
public:
    int knapsack(int w, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        // dp[i][w] stores max value using items [0..i] with capacity w
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        return memoization(n - 1, w, val, wt, dp);
    }

private:
    int memoization(int i, int w, vector<int> &val, vector<int> &wt,
                    vector<vector<int>> &dp)
    {
        if (i == 0) // Base case: only the first item is available
        {
            if (wt[i] <= w) // If it fits, take it
                return val[i];
            else // Otherwise can't take
                return 0;
        }

        if (dp[i][w] != -1) // If already computed, return stored value
            return dp[i][w];

        // Take the item (only if it fits):
        int pick = (wt[i] <= w) ? val[i] + memoization(i - 1, w - wt[i], val, wt, dp) : -1e9;
        // Don't take the item:
        int notPick = memoization(i - 1, w, val, wt, dp);

        // Store and return max of two choices
        return dp[i][w] = max(pick, notPick);
    }
};

// Tabulation :
class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        // dp[i][w] → max value using items [0..i] with capacity w
        vector<vector<int>> dp(n, vector<int>(W + 1, 0));

        // Base case: fill row for first item
        for (int w = 0; w <= W; ++w)
            dp[0][w] = (wt[0] <= w) ? val[0] : 0;

        // Fill dp table iteratively
        for (int i = 1; i < n; ++i)
        {
            for (int w = 0; w <= W; ++w)
            {
                // Pick only if it will fit in the bag :
                int pick = (wt[i] <= w) ? pick = val[i] + dp[i - 1][w - wt[i]] : -1e9;
                // Don't pick case :
                int notPick = dp[i - 1][w];
                // Store max
                dp[i][w] = max(pick, notPick);
            }
        }
        return dp[n - 1][W]; // Final answer
    }
};

// Space optimisation :
class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        // Only need previous row and current row
        vector<int> prev(W + 1, 0), curr(W + 1, 0);

        // Base case: first item
        for (int w = 0; w <= W; ++w)
            prev[w] = (wt[0] <= w) ? val[0] : 0;

        // Build DP iteratively
        for (int i = 1; i < n; ++i)
        {
            for (int w = 0; w <= W; ++w)
            {
                int pick = (wt[i] <= w) ? val[i] + prev[w - wt[i]] : -1e9;
                int notPick = prev[w];
                curr[w] = max(pick, notPick);
            }
            prev = curr; // Move current row to prev for next iteration
        }
        return prev[W];
    }
};

// Only one 1D array Space-Optimisation :
class Solution
{
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        // Use only one array to store results for all items
        vector<int> prev(W + 1, 0);

        // Base case: first item
        for (int w = 0; w <= W; ++w)
            prev[w] = (wt[0] <= w) ? val[0] : 0;

        // Process all items
        for (int i = 1; i < n; ++i)
        {
            // IMPORTANT: Traverse weights from right to left (W → 0)
            // to avoid overwriting values that are still needed.
            for (int w = W; w >= 0; --w)
            {
                // If we pick item i (only if weight fits)
                int pick = (wt[i] <= w) ? val[i] + prev[w - wt[i]] : -1e9;
                // If we don't pick item i
                int notPick = prev[w];
                // Update dp array in place
                prev[w] = max(pick, notPick);
            }
        }
        return prev[W]; // Final answer
    }
};
