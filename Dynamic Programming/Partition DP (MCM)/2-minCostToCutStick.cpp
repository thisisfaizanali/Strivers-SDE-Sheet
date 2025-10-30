/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class Solution
{
private:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        // Base case: no cuts left
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        // Try making every possible cut between i and j
        for (int k = i; k <= j; ++k)
        {
            // Cost of this cut = length of current stick segment
            int cost = (cuts[j + 1] - cuts[i - 1]) +
                       solve(i, k - 1, cuts, dp) + // left piece
                       solve(k + 1, j, cuts, dp);  // right piece

            mini = min(mini, cost); // take the minimum total cost
        }

        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        // Add boundaries 0 and n :
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort all cut positions :
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, -1));

        // Solve for cuts between indices 1 and c-2
        // (since 0 and n are the artificial boundaries)
        return solve(1, c - 2, cuts, dp);
    }
};

// Tabulation :
class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        //  Add boundaries 0 and n :
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort the array :
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();
        vector<vector<int>> dp(c, vector<int>(c, 0));

        for (int i = c - 2; i >= 1; --i)
        { // start from end
            for (int j = i; j <= c - 2; ++j)
            {
                int mini = INT_MAX;

                // Try every possible cut between i and j
                for (int k = i; k <= j; ++k)
                {
                    int cost = (cuts[j + 1] - cuts[i - 1]) +
                               dp[i][k - 1] + // left segment cost
                               dp[k + 1][j];  // right segment cost
                    mini = min(mini, cost);
                }

                // If no cuts possible, cost = 0
                dp[i][j] = (mini == INT_MAX) ? 0 : mini;
            }
        }

        // The whole stick corresponds to cuts[1..c-2]
        return dp[1][c - 2];
    }
};