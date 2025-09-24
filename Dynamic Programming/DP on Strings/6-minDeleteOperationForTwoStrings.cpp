/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

/*
Formula Derivation: m + n - (2 * LCS_length)
- To make both strings identical, we keep only the Longest Common Subsequence (LCS)
- Characters to delete from word1 = m - LCS_length
- Characters to delete from word2 = n - LCS_length
- Total deletions = (m - LCS_length) + (n - LCS_length) = m + n - 2*LCS_length
*/

// Tabulation :
class Solution
{
public:
    int minDistance(string &word1, string &word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int minDistance = m + n - (2 * dp[m][n]);
        return minDistance;
    }
};

// Space optimisation :
class Solution
{
public:
    int minDistance(string &word1, string &word2)
    {
        int m = word1.size(), n = word2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                    curr[j] = 1 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return m + n - (2 * prev[n]);
    }
};
