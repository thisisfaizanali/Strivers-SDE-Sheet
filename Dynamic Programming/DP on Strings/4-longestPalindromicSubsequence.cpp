/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Tabulation :
class Solution
{
public:
    // Trick: Longest Palindromic Subsequence = LCS of string with its reverse
    // Why it works: Any common subsequence between s and reverse(s) reads same forwards/backwards
    // Converting palindrome problem to well-known LCS problem
    int longestPalindromeSubseq(string &s)
    {
        int m = s.size();
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (s[i - 1] == reversed[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][m];
    }
};

// Space optimization :
class Solution
{
public:
    // Trick: Longest Palindromic Subsequence = LCS of string with its reverse
    // Why it works: Any common subsequence between s and reverse(s) reads same forwards/backwards
    // Converting palindrome problem to well-known LCS problem
    int longestPalindromeSubseq(string &s)
    {
        int m = s.size();
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (s[i - 1] == reversed[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[m];
    }
};
