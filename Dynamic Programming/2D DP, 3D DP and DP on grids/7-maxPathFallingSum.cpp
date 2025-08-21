/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization Approach - Top Down DP:
class Solution
{
private:
    const int NINF = -1e9; // Use -1e9 instead of INT_MIN to avoid underflow when adding matrix values

private:
    int memoization(int i, int j, vector<vector<int>> &mat,
                    vector<vector<int>> &memo)
    {
        int n = mat.size();    // number of rows
        int m = mat[0].size(); // number of columns

        // Base case: Out of bounds columns return negative infinite value
        if (j < 0 || j >= m)
            return NINF;

        // Base case: First row - return the cell value itself
        if (i == 0)
            return mat[0][j];

        // Return memoized result if already computed
        if (memo[i][j] != -1001)
            return memo[i][j];

        // Transition: Try all three possible moves from previous row
        int up = mat[i][j] + memoization(i - 1, j, mat, memo);                  // Move straight up
        int diagonallyRight = mat[i][j] + memoization(i - 1, j + 1, mat, memo); // Move diagonally up-right
        int diagonallyLeft = mat[i][j] + memoization(i - 1, j - 1, mat, memo);  // Move diagonally up-left

        // Store and return maximum cost path
        return memo[i][j] = max({up, diagonallyLeft, diagonallyRight});
    }

public:
    int maximumPath(vector<vector<int>> &mat)
    {
        int n = mat.size();                                 // number of rows
        int m = mat[0].size();                              // number of columns
        vector<vector<int>> memo(n, vector<int>(m, -1001)); // Initialize memoization table with sentinel value
        int ans = NINF;

        // Try starting from each column in the last row (since we're going top-down)
        for (int j = 0; j < m; ++j)
            ans = max(ans, memoization(n - 1, j, mat, memo));

        return ans;
    }
};

// Tabulation Approach - Bottom Up DP:
class Solution
{
private:
    const int NINF = -1e9; // Use -1e9 instead of INT_MIN to avoid underflow when adding matrix values

public:
    int maximumPath(vector<vector<int>> &mat)
    {
        int n = mat.size();                              // number of rows
        int m = mat[0].size();                           // number of columns
        vector<vector<int>> dp(n, vector<int>(m, NINF)); // DP table initialization

        // Base case: Fill first row with original matrix values
        for (int j = 0; j < m; ++j)
            dp[0][j] = mat[0][j];

        // Fill DP table row by row from top to bottom
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                // Transition: Calculate cost from all possible previous positions
                int up = mat[i][j] + dp[i - 1][j];                                     // From directly above
                int diagonallyRight = j + 1 < m ? mat[i][j] + dp[i - 1][j + 1] : NINF; // From top-left (bounds check)
                int diagonallyLeft = j > 0 ? mat[i][j] + dp[i - 1][j - 1] : NINF;      // From top-right (bounds check)

                // Store maximum cost to reach current cell
                dp[i][j] = max({up, diagonallyLeft, diagonallyRight});
            }
        }

        // Return maximum value from last row (all possible ending positions)
        return *max_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// Space Optimization - Using only two rows:
class Solution
{
private:
    const int NINF = -1e9; // Use -1e9 instead of INT_MIN to avoid underflow when adding matrix values

public:
    int maximumPath(vector<vector<int>> &mat)
    {
        int n = mat.size();                // number of rows
        int m = mat[0].size();             // number of columns
        vector<int> prev(m, 0), cur(m, 0); // Only store previous and current row

        // Base case: Initialize first row in prev array
        for (int j = 0; j < m; ++j)
            prev[j] = mat[0][j];

        // Process each row starting from second row
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                // Transition: Calculate maximum cost from three possible previous positions
                int up = prev[j];                                       // From directly above
                int diagonallyLeft = (j > 0) ? prev[j - 1] : NINF;      // From top-right (bounds check)
                int diagonallyRight = (j + 1 < m) ? prev[j + 1] : NINF; // From top-left (bounds check)

                // Current cell = matrix value + maximum of three transitions
                cur[j] = mat[i][j] + max({up, diagonallyLeft, diagonallyRight});
            }
            prev = cur; // Move current row to previous for next iteration
        }

        // Return maximum value from the final row
        return *max_element(prev.begin(), prev.end());
    }
};
