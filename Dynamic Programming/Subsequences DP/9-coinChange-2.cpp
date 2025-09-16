/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization : better than tabulation for this problem :
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        // dp[i][a] stores the number of ways to make 'a' using coins[0..i]
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return solve(n - 1, amount, coins, dp);
    }

private:
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        // Base case: if amount is 0, we found 1 way
        if (amount == 0)
            return 1; // not picking is picking
        // If only one type of coin left (coins[0])
        if (i == 0)
        {
            // If amount is divisible by coins[0], then there's exactly 1 way
            if (amount % coins[0] == 0)
                return 1;
            else
                return 0;
        }
        // If already computed, return from dp
        if (dp[i][amount] != -1)
            return dp[i][amount];

        // Pick the coin at index i (if it's not greater than current amount)
        int pick = (coins[i] <= amount) ? solve(i, amount - coins[i], coins, dp) : 0;
        // Do not pick the coin at index i, move to previous coin
        int notPick = solve(i - 1, amount, coins, dp);

        // Store and return the total ways
        return dp[i][amount] = pick + notPick;
    }
};

// Tabulation : overflow error even after using long long
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

        // Base case: making amount = 0 with any coins has 1 way (use no coins)
        for (int i = 0; i < n; ++i)
            dp[i][0] = 1;

        // Base case for the first coin: only possible if divisible by coins[0]
        for (int a = 0; a <= amount; ++a)
            dp[0][a] = (a % coins[0] == 0) ? 1 : 0;

        // Fill dp table
        for (int i = 1; i < n; ++i)
        {
            for (int a = 0; a <= amount; ++a)
            {
                long long pick = (coins[i] <= a) ? dp[i][a - coins[i]] : 0;
                long long notPick = dp[i - 1][a];
                dp[i][a] = pick + notPick;
            }
        }
        return dp[n - 1][amount];
    }
};

// Space Optimization using prev and curr :
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<long long> prev(amount + 1, 0), curr(amount + 1, 0);

        // Base case for the first coin
        for (int a = 0; a <= amount; ++a)
            prev[a] = (a % coins[0] == 0) ? 1 : 0;

        for (int i = 1; i < n; ++i)
        {
            curr[0] = 1; // amount = 0 always has 1 way
            for (int a = 1; a <= amount; ++a)
            {
                long long pick = (coins[i] <= a) ? curr[a - coins[i]] : 0;
                long long notPick = prev[a];
                curr[a] = pick + notPick;
            }
            prev = curr;
        }

        return prev[amount];
    }
};

// Space Optimization using one dp array only :
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<long long> dp(amount + 1, 0);

        // Base case: amount 0 can always be made in 1 way
        dp[0] = 1;

        // Iterating over coins
        for (int i = 0; i < n; ++i)
        {
            for (int a = coins[i]; a <= amount; ++a)
            {
                dp[a] += dp[a - coins[i]];
            }
        }

        return dp[amount];
    }
};
