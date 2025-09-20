/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); // DP table, -1 means not computed yet
        return solve(m - 1, n - 1, dp, text1, text2);  // Start from last characters of both strings
    }

private:
    int solve(int i, int j, vector<vector<int>> &dp, string &text1, string &text2)
    {
        if (i < 0 || j < 0) // If we run out of characters in any string
            return 0;
        if (dp[i][j] != -1) // Already computed
            return dp[i][j];
        if (text1[i] == text2[j])                                        // Characters match
            return dp[i][j] = 1 + solve(i - 1, j - 1, dp, text1, text2); // Take diagonal +1
        return dp[i][j] = max(
                   solve(i - 1, j, dp, text1, text2), // Skip char from text1
                   solve(i, j - 1, dp, text1, text2)  // Skip char from text2
               );
    }
};

// Tabulation :
class Solution
{
public:
    // Here we shift the index towards the right by 1
    // to avoid complicated bounds check
    // so for comparison i and j become i - 1 and j - 1
    // but dont touch the recurrence relation :
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // DP table with extra row & col for empty strings

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])    // Characters match
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // Diagonal + 1
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Max of top or left
            }
        }
        return dp[m][n]; // Answer in bottom-right cell
    }
};

// Space optimization :
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0); // Only need previous and current rows

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1]; // Diagonal from previous row
                else
                    curr[j] = max(prev[j], curr[j - 1]); // Max of above or left
            }
            prev = curr; // Move current row to previous for next iteration
        }
        return prev[n]; // Last element has the answer
    }
};
