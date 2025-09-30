/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization:
class Solution
{
public:
    int minDistance(string &w1, string &w2)
    {
        int m = w1.size(), n = w2.size();
        // Initialize dp table with -1 (uncomputed state)
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, w1, w2, dp);
    }

private:
    // Memoized recursive function
    int solve(int i, int j, string &w1, string &w2, vector<vector<int>> &dp)
    {
        // Base case: if w1 is exhausted, insert remaining characters from w2
        if (i < 0)
            return j + 1;
        // Base case: if w2 is exhausted, delete remaining characters from w1
        if (j < 0)
            return i + 1;

        // If already computed, return cached result
        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match, no operation needed, move both pointers back
        if (w1[i] == w2[j])
            return dp[i][j] = solve(i - 1, j - 1, w1, w2, dp);

        // If characters don't match, try all three operations:
        int insert_op = 1 + solve(i, j - 1, w1, w2, dp);      // Insert w2[j-1]
        int delete_op = 1 + solve(i - 1, j, w1, w2, dp);      // Delete w1[i-1]
        int replace_op = 1 + solve(i - 1, j - 1, w1, w2, dp); // Replace w1[i-1] with w2[j-1]

        // Store and return minimum of all three operations
        return dp[i][j] = min({insert_op, delete_op, replace_op});
    }
};

// Tabulation:
class Solution
{
public:
    int minDistance(string &w1, string &w2)
    {
        int m = w1.size(), n = w2.size();
        // dp[i][j] = min operations to convert w1[0..i-1] to w2[0..j-1]
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Base case: first row - converting empty w1 to w2[0..j-1] requires j insertions
        for (int j = 0; j <= n; ++j)
            dp[0][j] = j;

        // Base case: first column - converting w1[0..i-1] to empty w2 requires i deletions
        for (int i = 0; i <= m; ++i)
            dp[i][0] = i;

        // Fill the dp table bottom-up
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // If characters match, no operation needed, copy diagonal value
                if (w1[i - 1] == w2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    // Take minimum of: insert (left), replace (diagonal), delete (top)
                    dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]});
            }
        }
        // Result is in bottom-right corner
        return dp[m][n];
    }
};

// 2D Space optimization:
class Solution
{
public:
    int minDistance(string &w1, string &w2)
    {
        int m = w1.size(), n = w2.size();
        // prev = previous row (i-1), curr = current row (i)
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // Initialize first row: converting empty w1 to w2[0..j-1] requires j insertions
        for (int j = 0; j <= n; ++j)
            prev[j] = curr[j] = j;

        // Process each row (each character of w1)
        for (int i = 1; i <= m; ++i)
        {
            // First column: converting w1[0..i-1] to empty w2 requires i deletions
            curr[0] = i;

            // Fill current row based on previous row
            for (int j = 1; j <= n; ++j)
            {
                // If characters match, no operation needed, take diagonal value
                if (w1[i - 1] == w2[j - 1])
                    curr[j] = prev[j - 1];
                else
                    // Take minimum of: insert (curr[j-1]), replace (prev[j-1]), delete (prev[j])
                    curr[j] = 1 + min({curr[j - 1], prev[j - 1], prev[j]});
            }
            // Move current row to previous for next iteration
            prev = curr;
        }
        // Result is in last position of prev array
        return prev[n];
    }
};
