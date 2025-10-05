/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // DP table: dp[index][buy/sell state][transactions remaining]
        // buy: 1 = can buy, 0 = can sell (holding stock)
        // cap: number of complete buy-sell transactions we can still make (0 to 2)
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp); // Start at day 0, can buy, 2 transactions left
    }

private:
    int solve(int i, int buy, int cap, vector<int> &prices,
              vector<vector<vector<int>>> &dp)
    {
        // Base case: reached end of array
        if (i == prices.size())
            return 0;
        // Base case: no transactions left
        if (cap == 0)
            return 0;
        // Return memoized result if already computed
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;
        if (buy) // Currently in "can buy" state
        {
            // Option 1: Buy stock today (spend money, transition to "can sell" state)
            int canB = -prices[i] + solve(i + 1, 0, cap, prices, dp);
            // Option 2: Skip buying today (stay in "can buy" state)
            int notB = solve(i + 1, 1, cap, prices, dp);
            profit = max(canB, notB);
        }
        else // Currently in "can sell" state (holding stock)
        {
            // Option 1: Sell stock today (earn money, complete transaction, transition to "can buy")
            int canS = prices[i] + solve(i + 1, 1, cap - 1, prices, dp);
            // Option 2: Skip selling today (stay in "can sell" state)
            int notS = solve(i + 1, 0, cap, prices, dp);
            profit = max(canS, notS);
        }
        // Memoize and return the result
        return dp[i][buy][cap] = profit;
    }
};

// Tabulation :
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // DP table initialized to 0 (base cases already satisfied)
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Base case 1: when cap = 0 (no transactions left), profit = 0
        for (int i = 0; i < n; ++i)
        {
            for (int b = 0; b <= 1; ++b)
            {
                dp[i][b][0] = 0;
            }
        }

        // Base case 2: when i = n (no more days), profit = 0
        for (int b = 0; b <= 1; ++b)
        {
            for (int c = 0; c <= 2; ++c)
            {
                dp[n][b][c] = 0;
            }
        }

        // Fill DP table bottom-up (from day n-1 to day 0)
        for (int i = n - 1; i >= 0; --i)
        {
            for (int b = 0; b <= 1; ++b)
            {
                // Start from c=1 to avoid negative index when computing c-1
                for (int c = 1; c <= 2; ++c)
                {
                    if (b) // Can buy state
                    {
                        // Buy today: pay price, transition to "can sell" state
                        int canBuy = -prices[i] + dp[i + 1][0][c];
                        // Don't buy: stay in "can buy" state
                        int notBuy = dp[i + 1][1][c];
                        dp[i][b][c] = max(canBuy, notBuy);
                    }
                    else // Can sell state (holding stock)
                    {
                        // Sell today: earn price, complete transaction, go to "can buy"
                        int canSell = prices[i] + dp[i + 1][1][c - 1];
                        // Don't sell: stay in "can sell" state
                        int notSell = dp[i + 1][0][c];
                        dp[i][b][c] = max(canSell, notSell);
                    }
                }
            }
        }
        // Answer: start at day 0, can buy state, with 2 transactions available
        return dp[0][1][2];
    }
};

// Space Optimization to 2D Arrays:
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // Only need current day and next day states (space optimized from 3D to 2D)
        vector<vector<int>> curr(2, vector<int>(3, 0)), ahead(2, vector<int>(3, 0));

        // Base case initialization for cap = 0
        for (int i = 0; i < n; ++i)
        {
            for (int b = 0; b <= 1; ++b)
            {
                curr[b][0] = 0;
            }
        }

        // Base case initialization for i = n (ahead array)
        for (int b = 0; b <= 1; ++b)
        {
            for (int c = 0; c <= 2; ++c)
            {
                ahead[b][c] = 0;
            }
        }

        // Fill from day n-1 to day 0
        for (int i = n - 1; i >= 0; --i)
        {
            for (int b = 0; b <= 1; ++b)
            {
                for (int c = 1; c <= 2; ++c)
                {
                    if (b) // Can buy
                    {
                        int canBuy = -prices[i] + ahead[0][c];
                        int notBuy = ahead[1][c];
                        curr[b][c] = max(canBuy, notBuy);
                    }
                    else // Can sell
                    {
                        int canSell = prices[i] + ahead[1][c - 1];
                        int notSell = ahead[0][c];
                        curr[b][c] = max(canSell, notSell);
                    }
                }
            }
            // Update ahead to current for next iteration
            ahead = curr;
        }
        // Answer stored in ahead after all iterations
        return ahead[1][2];
    }
};

// Alternative Representation: Can be optimized to dp[n][4]
// Instead of tracking [buy/sell state][transactions], we can track 4 transaction states:
// State 0: First buy
// State 1: First sell
// State 2: Second buy
// State 3: Second sell
// This reduces space from dp[n][2][3] to dp[n][4] with simpler transitions
// Each state directly represents progress through the two allowed transactions

// The four variable optimization is not intuitive :
