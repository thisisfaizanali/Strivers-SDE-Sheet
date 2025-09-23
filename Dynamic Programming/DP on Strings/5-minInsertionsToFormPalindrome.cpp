/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Tabulation :
class Solution
{
public:
    // Trick: Minimum insertions = Total length m  - Longest Palindromic Subsequence
    // Why: LPS is the "already palindromic" part, everything else must be fixed
    int minInsertions(string &s)
    {
        int m = s.size();
        string reversed = s;
        reverse(reversed.begin(), reversed.end());

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        // Compute LCS(s, reversed)
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

        int lps = dp[m][m];
        return m - lps;
    }
};

// Space optimization :
class Solution
{
public:
    // Trick: Minimum insertions = Total length m - Longest Palindromic Subsequence
    // Use rolling arrays to reduce space from O(n^2) -> O(n)
    int minInsertions(string &s)
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

        int lps = prev[m];
        return m - lps;
    }
};
