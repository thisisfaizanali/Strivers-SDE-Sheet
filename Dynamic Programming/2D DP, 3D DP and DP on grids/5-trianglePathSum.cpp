/*++++++++++++++++++++++++++++++++++++++++++++++++++++++ Bismillah ++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class SolutionMemo
{
private:
    int memoization(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &memo)
    {
        int n = triangle.size();

        // Base case: last row
        if (i == n - 1)
            return triangle[i][j];

        if (memo[i][j] != -1)
            return memo[i][j];

        // Option 1: Go straight down
        int down = triangle[i][j] + memoization(i + 1, j, triangle, memo);
        // Option 2: Go diagonally down-right
        int diagonal = triangle[i][j] + memoization(i + 1, j + 1, triangle, memo);

        // Store and return the minimum of the two
        return memo[i][j] = min(down, diagonal);
    }

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return memoization(0, 0, triangle, memo);
    }
};

// Tabulation :
class SolutionTab
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: fill the last row
        for (int j = 0; j < n; ++j)
            dp[n - 1][j] = triangle[n - 1][j];

        // Bottom-up: start from second last row
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0]; // Top element holds the answer
    }
};

// Space Optimization :
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();

        // `prev` stores the results of the row below
        vector<int> prev(n, 0), curr(n, 0);

        // Base case: initialize with last row
        for (int j = 0; j < n; ++j)
            prev[j] = triangle[n - 1][j];

        // Iterate from second last row up to top
        for (int i = n - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                int down = triangle[i][j] + prev[j];
                int diagonal = triangle[i][j] + prev[j + 1];
                curr[j] = min(down, diagonal);
            }
            // Update `prev` to be the `curr` row for next iteration
            prev = curr;
        }

        return prev[0]; // Top element result
    }
};
