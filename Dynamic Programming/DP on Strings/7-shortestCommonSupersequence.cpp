/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Leetcode problem -> find the actual string :
class Solution
{
public:
    string shortestCommonSupersequence(string &str1, string &str2)
    {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Backtrack to build the supersequence
        string result = "";
        int i = m, j = n;

        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                // Common character (LCS) - add once and move diagonally
                result = str1[i - 1] + result;
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                // str1[i-1] was chosen in optimal path - include it
                result = str1[i - 1] + result;
                i--;
            }
            else
            {
                // str2[j-1] was chosen in optimal path - include it
                result = str2[j - 1] + result;
                j--;
            }
        }

        // Add remaining characters from str1 (when str2 is exhausted)
        while (i > 0)
        {
            result = str1[i - 1] + result;
            i--;
        }
        // Add remaining characters from str2 (when str1 is exhausted)
        while (j > 0)
        {
            result = str2[j - 1] + result;
            j--;
        }

        return result;
    }
};

// GFG problem -> find only the length :
// Formula derivation: SCS_length = len(str1) + len(str2) - LCS_length
// Explanation: We need all characters from both strings, but common characters (LCS) are counted only once
class Solution
{
public:
    int shortestCommonSupersequence(string &str1, string &str2)
    {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return m + n - dp[m][n];
    }
};
