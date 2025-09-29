/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class Solution
{
public:
    int numDistinct(string &s, string &t)
    {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); // dp[i][j] = number of distinct subsequences of s[0..i] that match t[0..j]
        return solve(m - 1, n - 1, s, t, dp);          // start from last indices of both strings
    }

private:
    int solve(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        // Base cases
        if (j < 0)
            return 1; // Matched entire t - we found one valid subsequence
        if (i < 0)
            return 0; // Ran out of s, but t remains - no valid subsequence possible

        // Check memo
        if (dp[i][j] != -1)
            return dp[i][j]; // return already computed result

        // Recurrence
        if (s[i] == t[j])
            dp[i][j] = solve(i - 1, j - 1, s, t, dp) + solve(i - 1, j, s, t, dp); // if chars match: (use this char in matching) + (skip this char)
        else
            dp[i][j] = solve(i - 1, j, s, t, dp); // if chars don't match: skip current char in s

        return dp[i][j];
    }
};

// Tabulation :
class Solution
{
public:
    int numDistinct(string &s, string &t)
    {
        int m = s.size(), n = t.size();
        vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0)); // dp[i][j] = number of ways to form t[0..j-1] from s[0..i-1]
        for (int i = 0; i <= m; ++i)
            dp[i][0] = 1; // empty string t can be formed in exactly 1 way (by selecting nothing)
        for (int j = 1; j <= n; ++j)
            dp[0][j] = 0; // non-empty t cannot be formed from empty s
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; // if chars match: (use s[i-1] to match t[j-1]) + (don't use s[i-1])
                else
                    dp[i][j] = dp[i - 1][j]; // if chars don't match: carry forward previous result (skip s[i-1])
            }
        }
        return (int)dp[m][n]; // final answer: ways to form entire t from entire s
    }
};

// 2D array Space optimization :
class Solution
{
public:
    int numDistinct(string &s, string &t)
    {
        int m = s.size(), n = t.size();
        vector<double> prev(n + 1, 0), curr(n + 1, 0); // prev = previous row, curr = current row in dp table
        curr[0] = 1;                                   // base case: empty t from first 0 chars of s
        prev[0] = 1;                                   // base case: empty t from any prefix of s
        for (int i = 1; i <= m; ++i)
        {
            curr[0] = 1; // empty t can always be formed (base case for each row)
            for (int j = 1; j <= n; ++j)
            {
                if (s[i - 1] == t[j - 1])
                    curr[j] = prev[j - 1] + prev[j]; // if match: (use char from diagonal) + (skip char from above)
                else
                    curr[j] = prev[j]; // if no match: take value from above (previous row, same column)
            }
            prev = curr; // move current row to previous for next iteration
        }
        return (int)prev[n]; // result is in last position of prev array
    }
};

// 1D array Space optimization :
class Solution
{
public:
    int numDistinct(string &s, string &t)
    {
        int m = s.size(), n = t.size();
        vector<double> dp(n + 1, 0); // single array to store current state
        dp[0] = 1;                   // base case: empty t can be formed in 1 way
        for (int i = 1; i <= m; ++i)
        {
            for (int j = n; j >= 1; --j) // traverse right to left to avoid overwriting values we still need
            {
                if (s[i - 1] == t[j - 1])
                    dp[j] = dp[j - 1] + dp[j]; // if match: add (diagonal value) + (current value which represents previous row)
                // if no match: dp[j] stays same (implicitly using previous row's value)
            }
        }
        return (int)dp[n]; // final answer at last position
    }
};
