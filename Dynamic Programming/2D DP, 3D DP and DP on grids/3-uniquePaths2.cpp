/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution
{
private:
    int memoization(int i, int j, vector<vector<int>> &obstacleGrid, vector<vector<int>> &memo)
    {
        if (i < 0 || j < 0) // base case: out of bounds
            return 0;
        if (obstacleGrid[i][j] == 1) // base case: obstacle cell
            return 0;
        if (i == 0 && j == 0) // base case: starting cell
            return 1;
        if (memo[i][j] != -1) // already computed
            return memo[i][j];

        int up = memoization(i - 1, j, obstacleGrid, memo);   // from top
        int left = memoization(i, j - 1, obstacleGrid, memo); // from left
        return memo[i][j] = up + left;                        // store & return
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // if start or end cell is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> memo(m, vector<int>(n, -1));      // memo table
        return memoization(m - 1, n - 1, obstacleGrid, memo); // start from destination
    }
};

// Tabulation
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // if start or end cell is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp table
        dp[0][0] = 1;                                 // starting cell

        for (int i = 0; i < m; ++i) // iterate rows
        {
            for (int j = 0; j < n; ++j) // iterate columns
            {
                if (i == 0 && j == 0) // skip starting cell
                    continue;
                if (obstacleGrid[i][j] == 1) // obstacle cell
                {
                    dp[i][j] = 0;
                    continue;
                }
                if (i > 0) // from top
                    dp[i][j] += dp[i - 1][j];
                if (j > 0) // from left
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1]; // return bottom-right cell
    }
};

// Space optimization
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // if start or end cell is blocked
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
            return 0;

        vector<int> prev(n, 0), curr(n, 0); // arrays for previous and current rows

        for (int i = 0; i < m; ++i) // iterate rows
        {
            for (int j = 0; j < n; ++j) // iterate columns
            {
                if (obstacleGrid[i][j] == 1) // obstacle cell
                {
                    curr[j] = 0;
                    continue;
                }

                if (i == 0 && j == 0) // starting cell
                {
                    curr[j] = 1;
                }
                else
                {
                    int up = 0, left = 0;
                    if (i > 0) // from top
                        up = prev[j];
                    if (j > 0) // from left
                        left = curr[j - 1];
                    curr[j] = up + left; // store sum
                }
            }
            prev = curr; // move to next row
        }
        return prev[n - 1]; // return bottom-right cell
    }
};
