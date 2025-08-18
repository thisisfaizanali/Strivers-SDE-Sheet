/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization (Top-down)
class SolutionMemo
{
private:
    int memoization(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &memo)
    {
        if (i < 0 || j < 0) // out of bounds
            return INT_MAX;
        if (i == 0 && j == 0) // starting cell
            return grid[0][0];
        if (memo[i][j] != -1) // already computed
            return memo[i][j];

        int up = memoization(i - 1, j, grid, memo);
        int left = memoization(i, j - 1, grid, memo);
        memo[i][j] = grid[i][j] + min(up, left);
        return memo[i][j];
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return memoization(m - 1, n - 1, grid, memo);
    }
};

// Tabulation (Bottom-up)
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                int up = INT_MAX, left = INT_MAX;
                if (i > 0)
                    up = dp[i - 1][j] + grid[i][j];
                if (j > 0)
                    left = dp[i][j - 1] + grid[i][j];
                dp[i][j] = min(up, left);
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Space optimization
class SolutionOptimized
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n, 0);

        for (int i = 0; i < m; ++i)
        {
            vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    curr[j] = grid[i][j];
                }
                else
                {
                    int up = (i > 0) ? prev[j] : INT_MAX;
                    int left = (j > 0) ? curr[j - 1] : INT_MAX;
                    curr[j] = grid[i][j] + min(up, left);
                }
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};
