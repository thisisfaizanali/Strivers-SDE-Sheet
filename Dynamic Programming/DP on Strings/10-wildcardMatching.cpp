/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class Solution
{
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        // base case: both string and pattern exhausted → match
        if (i < 0 && j < 0)
            return true;

        // if string exhausted, but pattern still has characters
        if (i < 0 && j >= 0)
        {
            // check if all characters in p[0..j] are '*'
            // here j is an INDEX (0-based), so we must include p[j]
            // → loop runs from k = 0 to k <= j
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        // if pattern exhausted but string still left → no match
        if (j < 0 && i >= 0)
            return false;

        // if already computed, return from memo
        if (dp[i][j] != -1)
            return dp[i][j];

        // case 1: characters match, or '?' matches any single character
        if (p[j] == s[i] || p[j] == '?')
            return dp[i][j] = solve(i - 1, j - 1, s, p, dp);

        // case 2: '*' can match empty OR one/more characters
        // - match empty sequence → move left in pattern: solve(i, j - 1)
        // - match one char → move left in string: solve(i - 1, j)
        else if (p[j] == '*')
            return dp[i][j] = (solve(i, j - 1, s, p, dp) || solve(i - 1, j, s, p, dp));

        // case 3: mismatch
        else
            return dp[i][j] = false;
    }

public:
    bool isMatch(string &s, string &p)
    {
        int m = s.size(), n = p.size();
        // dp[i][j] stores result for substring s[0..i] vs p[0..j]
        // initialize with -1 meaning "not computed yet"
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, s, p, dp);
    }
};

// Tabulation :
class Solution
{
public:
    bool isMatch(string &s, string &p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // empty string matches empty pattern
        dp[0][0] = true;

        // empty string cannot match a non-empty pattern (unless pattern is all '*')
        for (int i = 1; i <= m; ++i)
            dp[i][0] = false;

        // fill first row: dp[0][j] means empty string vs pattern[0..j-1]
        for (int j = 1; j <= n; ++j)
        {
            dp[0][j] = true;
            // here j means "prefix length" of pattern
            // so we must check characters p[0..j-1] (length j)
            // → loop runs from k = 0 to k < j
            for (int k = 0; k < j; ++k)
            {
                if (p[k] != '*')
                {
                    dp[0][j] = false;
                    break;
                }
            }
        }

        // fill dp table bottom-up
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1]; // exact match or '?'
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; // '*' as empty OR one/more
                else
                    dp[i][j] = false; // mismatch
            }
        }
        return dp[m][n];
    }
};
