/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

/*
    - VERY IMPORTANT: You pay the cost of a step when you are ABOUT TO JUMP from it,
      not when you arrive on it.
*/

/* ============================ Memoization Approach ============================ */
class SolutionMemo
{
private:
    int memoization(int index, vector<int> &cost, vector<int> &memo)
    {
        // Base cases: starting at step 0 or step 1 costs nothing initially
        if (index == 0 || index == 1)
            return 0;

        // Return already computed result
        if (memo[index] != -1)
            return memo[index];

        // Jump from (index-1) → pay cost at (index-1)
        int jumpOne = cost[index - 1] + memoization(index - 1, cost, memo);

        // Jump from (index-2) → pay cost at (index-2)
        int jumpTwo = INT_MAX;
        if (index > 1)
            jumpTwo = cost[index - 2] + memoization(index - 2, cost, memo);

        // Store and return the minimum cost
        memo[index] = min(jumpOne, jumpTwo);
        return memo[index];
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> memo(n + 1, -1); // +1 to allow indexing up to n
        return memoization(n, cost, memo);
    }
};

/* ============================ Tabulation Approach ============================ */
class SolutionTab
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n + 1, 0); // dp[i] = min cost to reach step i

        dp[0] = 0; // starting at step 0 → no cost paid yet
        dp[1] = 0; // starting at step 1 → no cost paid yet

        for (int i = 2; i <= n; ++i)
        {
            // To reach i, you could have come from:
            // (i-1): pay cost at (i-1) before jumping
            int jumpOne = cost[i - 1] + dp[i - 1];

            // (i-2): pay cost at (i-2) before jumping
            int jumpTwo = cost[i - 2] + dp[i - 2];

            dp[i] = min(jumpOne, jumpTwo);
        }

        return dp[n];
    }
};
