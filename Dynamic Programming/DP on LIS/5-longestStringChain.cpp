/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkPredecessor(string &s1, string &s2)
    {
        // If s2 is not exactly one character longer than s1, return false
        if (1 + s1.size() != s2.size())
            return false;

        int i = 0, j = 0; // i -> index for s1, j -> index for s2

        // Traverse both strings and compare characters
        while (i < s1.size() && j < s2.size())
        {
            if (s1[i] == s2[j]) // if characters match, move both pointers
            {
                i++;
                j++;
            }
            else // if not match, skip one character in s2
                j++;
        }

        // If all characters in s1 are matched in order inside s2,
        // s1 is a predecessor of s2
        if (i == s1.size())
            return true;

        return false;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();

        // Sort words by length (shorter first)
        sort(words.begin(), words.end(), [](const string &a, const string &b)
             { return a.size() < b.size(); });

        // dp[i] will store the longest chain ending at words[i]
        vector<int> dp(n, 1);
        int maxLen = 1; // to track the maximum chain length found so far

        // For each word, check all shorter words before it
        for (int i = 0; i < n; ++i)
        {
            for (int p = 0; p < i; ++p)
            {
                // If words[p] is a predecessor of words[i],
                // update dp[i] accordingly
                if (checkPredecessor(words[p], words[i]) && 1 + dp[p] > dp[i])
                {
                    dp[i] = 1 + dp[p];
                    maxLen = max(maxLen, dp[i]); // update overall max
                }
            }
        }

        return maxLen;
    }
};
