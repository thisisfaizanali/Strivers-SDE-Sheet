/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Tabulation :
class Solution
{
public:
    // This is a variation of LCS :
    // Substring can only be contiguous :
    int longestCommonSubstring(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // DP table with extra row & col
        int maxLen = 0;                                       // Track maximum length found

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1]) // Characters match
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1]; // Extend substring from diagonal
                    maxLen = max(maxLen, dp[i][j]);  // Update maximum
                }
                else
                    dp[i][j] = 0; // Reset to 0 (key difference from LCS!)
            }
        }
        return maxLen; // Return maximum length found
    }
};

// Space optimization :
class Solution
{
public:
    int longestCommonSubstring(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0); // Only need previous and current rows
        int maxLen = 0;                             // Track maximum length

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    curr[j] = 1 + prev[j - 1];     // Diagonal from previous row
                    maxLen = max(maxLen, curr[j]); // Update maximum
                }
                else
                    curr[j] = 0; // Reset to 0 for substring
            }
            prev = curr; // Move current row to previous for next iteration
        }
        return maxLen; // Return maximum length found
    }
};
