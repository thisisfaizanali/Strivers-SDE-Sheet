/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution
{
private:
    int memoization(int i, int j, vector<vector<int>> &memo)
    {
        if (i == 0 && j == 0) // base case: starting cell
            return 1;
        if (i < 0 || j < 0) // base case: out of bounds
            return 0;
        if (memo[i][j] != -1) // return already computed value
            return memo[i][j];
        int up = memoization(i - 1, j, memo);   // move from top
        int left = memoization(i, j - 1, memo); // move from left
        return memo[i][j] = up + left;          // store and return result
    }

public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> memo(m, vector<int>(n, -1)); // initialize memo table
        return memoization(m - 1, n - 1, memo);          // start from destination
    }
};

// Tabulation
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0)); // dp table
        dp[0][0] = 1;                                 // starting cell

        for (int i = 0; i < m; ++i) // iterate rows
        {
            for (int j = 0; j < n; ++j) // iterate columns
            {
                if (i > 0) // if there is a cell above
                    dp[i][j] += dp[i - 1][j];
                if (j > 0) // if there is a cell to the left
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
    int uniquePaths(int m, int n)
    {
        vector<int> prev(n, 0), curr(n, 0); // arrays for previous and current rows

        for (int i = 0; i < m; ++i) // iterate rows
        {
            for (int j = 0; j < n; ++j) // iterate columns
            {
                if (i == 0 && j == 0) // starting cell
                    curr[j] = 1;
                else
                {
                    int up = 0, left = 0;
                    if (i > 0) // value from previous row
                        up += prev[j];
                    if (j > 0) // value from current row's previous column
                        left += curr[j - 1];
                    curr[j] = up + left; // store sum
                }
            }
            prev = curr; // move to next row
        }
        return prev[n - 1]; // return bottom-right value
    }
};

// Most optimal using Combination :
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // the most optimal solution is using combination :
        int totalMoves = (m - 1) + (n - 1); // down moves + right moves
        long long ans = 1;
        // ans is either choose m-1 down moves or n-1 right moves from
        // totalMoves : Using better method to calculate factorial :
        // can be derived from standard formula :
        int r = min(m - 1, n - 1); // to avoid overflow :
        for (int i = 1; i <= r; ++i)
            ans = ans * (totalMoves - r + i) / i;
        return static_cast<int>(ans);
    }
};
