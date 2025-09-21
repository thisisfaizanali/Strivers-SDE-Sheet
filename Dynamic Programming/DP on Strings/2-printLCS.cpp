/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// My method:
string findLCS(int m, int n, string &s1, string &s2)
{
    // Create DP table where each cell stores the actual LCS string (not just length)
    vector<vector<string>> dp(m + 1, vector<string>(n + 1, ""));
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])                  // Characters match at positions i-1 and j-1 (0-indexed)
                dp[i][j] = dp[i - 1][j - 1] + s1[i - 1]; // Extend previous LCS by adding current character
            else                                         // Characters don't match, take the longer LCS from either excluding s1[i-1] or s2[j-1]
                dp[i][j] = (dp[i - 1][j].size() > dp[i][j - 1].size()) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    return dp[m][n]; // Return the LCS of entire strings s1[0..m-1] and s2[0..n-1]
}

// Standard DP + Backtracking / Striver's Method :
string findLCS(int m, int n, string &s1, string &s2)
{
    // Create DP table storing only lengths (more memory efficient)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i)
        dp[i][0] = 0; // LCS of any string with empty string is 0
    for (int j = 0; j <= n; ++j)
        dp[0][j] = 0; // LCS of empty string with any string is 0
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i - 1] == s2[j - 1])          // Characters match (using 0-based indexing for strings)
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Add 1 to diagonal value
            else                                 // Characters don't match, take maximum from top or left cell
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Backtracking part : Reconstruct the actual LCS string from DP table
    string ans = "";
    int i = m, j = n;      // Start from bottom-right corner of DP table
    while (i > 0 && j > 0) // Continue until we reach empty string boundary
    {
        if (s1[i - 1] == s2[j - 1]) // If characters match, this char is part of LCS
        {
            ans += s1[i - 1]; // Add character to result (building in reverse order)
            i--;              // Move diagonally up-left in DP table
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) // LCS length came from top cell
            i--;                              // Move up (exclude current char from s1)
        else                                  // LCS length came from left cell (or both are equal)
            j--;                              // Move left (exclude current char from s2)
    }
    reverse(ans.begin(), ans.end()); // Reverse since we built the string backwards
    return ans;
}
