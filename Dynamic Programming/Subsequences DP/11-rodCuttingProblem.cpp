/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  +++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class SolutionMemo
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        // dp[i][l] = max profit for rod length l using pieces up to index i
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return memoization(n - 1, n, price, dp);
    }

private:
    int memoization(int i, int l, vector<int> &price, vector<vector<int>> &dp)
    {
        // Base case: If we're at index 0, we only have pieces of length 1 available
        // Maximum profit = use l pieces of length 1 = l * price[0]
        if (i == 0)
        {
            return l * price[0];
        }

        // If already computed, return stored value
        if (dp[i][l] != -1)
            return dp[i][l];

        int piece_length = i + 1; // index i corresponds to piece of length (i+1)

        // Option 1: Pick the current piece (length = i+1)
        // We can use it if piece_length <= remaining rod length l
        // After using, we can still use the same piece again (unbounded)
        int pick = (piece_length <= l) ? price[i] + memoization(i, l - piece_length, price, dp) : -1e9;

        // Option 2: Don't pick the current piece
        // Move to previous index (i-1) with same rod length l
        int notPick = memoization(i - 1, l, price, dp);

        return dp[i][l] = max(pick, notPick);
    }
};

// Tabulation :
class SolutionTab
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        // dp[i][l] = max profit for rod length l using pieces up to index i
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        // Base case 1: Zero profit for zero rod length (for all indices)
        for (int i = 0; i < n; ++i)
            dp[i][0] = 0;

        // Base case 2: For index 0 (only pieces of length 1 available)
        // For rod length l, maximum profit = l * price[0] (use l pieces of length 1)
        for (int l = 0; l <= n; ++l)
            dp[0][l] = l * price[0];

        // Fill DP table for all indices and rod lengths
        for (int i = 1; i < n; ++i)
        {
            for (int l = 0; l <= n; ++l)
            {
                int piece_length = i + 1; // Current piece length = index + 1

                // Option 1: Don't use current piece - take value from previous index
                int notPick = dp[i - 1][l];

                // Option 2: Use current piece if it fits in remaining rod length
                // After using, we can still use same piece again (unbounded knapsack)
                int pick = (piece_length <= l) ? price[i] + dp[i][l - piece_length] : -1e9;

                dp[i][l] = max(pick, notPick);
            }
        }
        return dp[n - 1][n];
    }
};

// Space optimization using two arrays :
class SolutionSpace2Rows
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        // Use only 2 rows: prev (i-1) and curr (i)
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // Initialize base case for index 0
        for (int l = 0; l <= n; ++l)
            prev[l] = l * price[0];

        for (int i = 1; i < n; ++i)
        {
            for (int l = 0; l <= n; ++l)
            {
                int piece_length = i + 1;

                // Option 1: Don't use current piece - take from previous row
                int notPick = prev[l];

                // Option 2: Use current piece - take from current row (unbounded)
                int pick = (piece_length <= l) ? price[i] + curr[l - piece_length] : -1e9;

                curr[l] = max(pick, notPick);
            }
            prev = curr; // Move current row to previous for next iteration
        }
        return prev[n];
    }
};

// Space optimization using one array :
class SolutionSpace1D
{
public:
    int cutRod(vector<int> &price)
    {
        int n = price.size();
        // dp[l] = max profit for rod length l
        vector<int> dp(n + 1, 0);

        // Initialize: Only pieces of length 1 available
        for (int l = 0; l <= n; ++l)
            dp[l] = l * price[0];

        // Process each piece length
        for (int i = 1; i < n; ++i)
        {
            int piece_length = i + 1;
            int piece_price = price[i];

            // Traverse left to right for unbounded knapsack
            // This allows reusing the same piece multiple times
            for (int l = 0; l <= n; ++l)
            {
                if (piece_length <= l)
                {
                    // We can either keep previous value or use current piece
                    dp[l] = max(dp[l], piece_price + dp[l - piece_length]);
                }
            }
        }
        return dp[n];
    }
};
