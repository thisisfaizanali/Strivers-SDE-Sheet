/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization Approach - Top Down DP:
class Solution
{
private:
    const int INF = 1e9; // Use 1e9 instead of INT_MAX to avoid overflow when adding matrix values

private:
    int memoization(int i, int j, vector<vector<int>> &matrix,
                    vector<vector<int>> &memo)
    {
        int n = matrix.size();

        // Base case: Out of bounds columns return infinite cost
        if (j < 0 || j >= n)
            return INF;

        // Base case: First row - return the cell value itself
        if (i == 0)
            return matrix[0][j];

        // Return memoized result if already computed
        if (memo[i][j] != -1)
            return memo[i][j];

        // Transition: Try all three possible moves from previous row
        int up = matrix[i][j] + memoization(i - 1, j, matrix, memo);                  // Move straight up
        int diagonallyRight = matrix[i][j] + memoization(i - 1, j + 1, matrix, memo); // Move diagonally up-right
        int diagonallyLeft = matrix[i][j] + memoization(i - 1, j - 1, matrix, memo);  // Move diagonally up-left

        // Store and return minimum cost path
        return memo[i][j] = min({up, diagonallyLeft, diagonallyRight});
    }

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> memo(n, vector<int>(n, -1)); // Initialize memoization table
        int ans = INF;

        // Try starting from each column in the last row (since we're going top-down)
        for (int j = 0; j < n; ++j)
            ans = min(ans, memoization(n - 1, j, matrix, memo));

        return ans;
    }
};

// Tabulation Approach - Bottom Up DP:
class Solution
{
private:
    const int INF = 1e9; // Use 1e9 instead of INT_MAX to avoid overflow when adding matrix values

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INF)); // DP table initialization

        // Base case: Fill first row with original matrix values
        for (int j = 0; j < n; ++j)
            dp[0][j] = matrix[0][j];

        // Fill DP table row by row from top to bottom
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // Transition: Calculate cost from all possible previous positions
                int up = matrix[i][j] + dp[i - 1][j];                                    // From directly above
                int diagonallyRight = j + 1 < n ? matrix[i][j] + dp[i - 1][j + 1] : INF; // From top-left (bounds check)
                int diagonallyLeft = j > 0 ? matrix[i][j] + dp[i - 1][j - 1] : INF;      // From top-right (bounds check)

                // Store minimum cost to reach current cell
                dp[i][j] = min({up, diagonallyLeft, diagonallyRight});
            }
        }

        // Return minimum value from last row (all possible ending positions)
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

// Space Optimization - Using only two rows:
class Solution
{
private:
    const int INF = 1e9; // Use 1e9 instead of INT_MAX to avoid overflow when adding matrix values

public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> prev(n, 0), cur(n, 0); // Only store previous and current row

        // Base case: Initialize first row in prev array
        for (int j = 0; j < n; ++j)
            prev[j] = matrix[0][j];

        // Process each row starting from second row
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // Transition: Calculate minimum cost from three possible previous positions
                int up = prev[j];                                      // From directly above
                int diagonallyLeft = (j > 0) ? prev[j - 1] : INF;      // From top-right (bounds check)
                int diagonallyRight = (j + 1 < n) ? prev[j + 1] : INF; // From top-left (bounds check)

                // Current cell = matrix value + minimum of three transitions
                cur[j] = matrix[i][j] + min({up, diagonallyLeft, diagonallyRight});
            }
            prev = cur; // Move current row to previous for next iteration
        }

        // Return minimum value from the final row
        return *min_element(prev.begin(), prev.end());
    }
};
