/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  +++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class SolutionMemo
{
public:
    int knapSack(int capacity, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return memoization(n - 1, capacity, val, wt, dp);
    }

private:
    int memoization(int i, int c, vector<int> &val, vector<int> &wt,
                    vector<vector<int>> &dp)
    {
        if (i == 0)
        {
            // Base case: with only the 0th item available, we can take at most (c / wt[0]) copies
            // (each contributing val[0] profit). So total profit = (c / wt[0]) * val[0].
            return (wt[0] <= c) ? val[0] * (c / wt[0]) : 0;
        }

        if (dp[i][c] != -1)
            return dp[i][c];

        // Pick (stay at i because infinite supply allowed)
        int pick = (wt[i] <= c) ? val[i] + memoization(i, c - wt[i], val, wt, dp) : -1e9;

        // Not pick (move to previous item)
        int notPick = memoization(i - 1, c, val, wt, dp);

        return dp[i][c] = max(pick, notPick);
    }
};

// Tabulation:
class SolutionTab
{
public:
    int knapSack(int capacity, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // Base case: with only the 0th item available, we can take at most (c / wt[0]) copies
        // (each contributing val[0] profit). So total profit = (c / wt[0]) * val[0].
        for (int c = 0; c <= capacity; ++c)
            dp[0][c] = (wt[0] <= c) ? val[0] * (c / wt[0]) : 0;

        for (int i = 1; i < n; ++i)
        {
            for (int c = 0; c <= capacity; ++c)
            {
                int pick = (wt[i] <= c) ? val[i] + dp[i][c - wt[i]] : -1e9;
                int notPick = dp[i - 1][c];
                dp[i][c] = max(pick, notPick);
            }
        }
        return dp[n - 1][capacity];
    }
};

// Space Optimization (2 rows) :
class SolutionSpace2Rows
{
public:
    int knapSack(int capacity, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<int> prev(capacity + 1, 0), curr(capacity + 1, 0);

        for (int c = 0; c <= capacity; ++c)
            prev[c] = (wt[0] <= c) ? val[0] * (c / wt[0]) : 0;

        for (int i = 1; i < n; ++i)
        {
            for (int c = 0; c <= capacity; ++c)
            {
                int pick = (wt[i] <= c) ? val[i] + curr[c - wt[i]] : -1e9;
                int notPick = prev[c];
                curr[c] = max(pick, notPick);
            }
            prev = curr;
        }
        return prev[capacity];
    }
};

// Space Optimization (1D) :
class SolutionSpace1D
{
public:
    int knapSack(int capacity, vector<int> &val, vector<int> &wt)
    {
        int n = val.size();
        vector<int> dp(capacity + 1, 0);

        for (int c = 0; c <= capacity; ++c)
            dp[c] = (wt[0] <= c) ? val[0] * (c / wt[0]) : 0;

        for (int i = 1; i < n; ++i)
        {
            // IMPORTANT: iterate left → right in unbounded knapsack.
            // This way, when we update dp[c], it can reuse the already updated dp[c - wt[i]]
            // from the same iteration, effectively allowing multiple copies of item i.
            // (In 0-1 knapsack we go right → left to forbid reusing the same item.)
            // Here we need multiple copies : so overwrite -> left to right only :
            for (int c = 0; c <= capacity; ++c)
            {
                if (wt[i] <= c)
                    dp[c] = max(dp[c], val[i] + dp[c - wt[i]]);
            }
        }
        return dp[capacity];
    }
};
