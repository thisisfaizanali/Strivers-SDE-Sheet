/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Buy and Sell Stock -3 code but cap value can go till k instead of 2 :
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // dp[i][b][c] where:
        // i = day index (0 to n)
        // b = buy state (1 = can buy, 0 = can sell/holding stock)
        // c = remaining COMPLETE transactions (0 to k)
        // NOTE: Here c represents transactions LEFT, not operations
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        // Base case: c=0 means no transactions left, profit = 0
        for (int i = 0; i < n; ++i)
        {
            for (int b = 0; b <= 1; ++b)
            {
                dp[i][b][0] = 0;
            }
        }

        // Base case: i=n means no days left, profit = 0
        for (int b = 0; b <= 1; ++b)
        {
            for (int c = 0; c <= k; ++c)
            {
                dp[n][b][c] = 0;
            }
        }

        // Fill DP table from last day to first day
        for (int i = n - 1; i >= 0; --i)
        {
            for (int b = 0; b <= 1; ++b)
            {
                // Only process when we have transactions remaining (c >= 1)
                for (int c = 1; c <= k; ++c)
                {
                    if (b) // Can buy
                    {
                        // Option 1: Buy today (pay price, move to sell state)
                        int canBuy = -prices[i] + dp[i + 1][0][c];
                        // Option 2: Skip buying today
                        int notBuy = dp[i + 1][1][c];
                        dp[i][b][c] = max(canBuy, notBuy);
                    }
                    else // Can sell (holding stock)
                    {
                        // Option 1: Sell today (get price, complete transaction, reduce c by 1)
                        int canSell = prices[i] + dp[i + 1][1][c - 1];
                        // Option 2: Skip selling today
                        int notSell = dp[i + 1][0][c];
                        dp[i][b][c] = max(canSell, notSell);
                    }
                }
            }
        }

        // Start at day 0, can buy, with k transactions available
        return dp[0][1][k];
    }
};

// Memoization :
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // dp[i][transaction] where:
        // i = day index (0 to n-1)
        // transaction = operation number (0 to 2k-1)
        // SIZE = 2*k+1 to accommodate indices 0 through 2k
        // But we only USE indices 0 through 2k-1 (that's 2k operations)
        // Index 2k serves as base case (all operations done)
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, -1));
        return solve(0, 0, k, prices, dp);
    }

private:
    int solve(int i, int transaction, int k, vector<int> &prices, vector<vector<int>> &dp)
    {
        // Base case 1: Exhausted all days
        // Base case 2: Completed all 2k operations (k buys + k sells)
        if (i == prices.size() || transaction == 2 * k)
            return 0;

        // Return cached result
        if (dp[i][transaction] != -1)
            return dp[i][transaction];

        int profit = 0;

        // Even transaction number = BUY operation
        // (0 = first buy, 2 = second buy, 4 = third buy, ...)
        if (!(transaction & 1))
        {
            // Option 1: Buy stock today (pay price, move to next operation)
            int canBuy = -prices[i] + solve(i + 1, transaction + 1, k, prices, dp);
            // Option 2: Skip buying today (stay on same operation)
            int notBuy = solve(i + 1, transaction, k, prices, dp);
            profit = max(canBuy, notBuy);
        }
        // Odd transaction number = SELL operation
        // (1 = first sell, 3 = second sell, 5 = third sell, ...)
        else
        {
            // Option 1: Sell stock today (get price, move to next operation)
            int canSell = prices[i] + solve(i + 1, transaction + 1, k, prices, dp);
            // Option 2: Skip selling today (stay on same operation)
            int notSell = solve(i + 1, transaction, k, prices, dp);
            profit = max(canSell, notSell);
        }

        return dp[i][transaction] = profit;
    }
};

// Tabulation :
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // dp[i][transaction] where:
        // i = day (0 to n)
        // transaction = operation number (0 to 2k)
        //
        // CRITICAL SIZE/LOOP UNDERSTANDING:
        // - Array size: 2*k+1 → valid indices are 0, 1, 2, ..., 2k
        // - Operations we compute: 0, 1, 2, ..., 2k-1 (that's 2k operations)
        // - Index 2k: Base case (all operations done, stays 0)
        //
        // WHY loop < 2*k and NOT <= 2*k?
        // When transaction = 2k-1, we access dp[i+1][transaction+1] = dp[i+1][2k] ✓ Valid!
        // When transaction = 2k, we'd access dp[i+1][2k+1] ✗ OUT OF BOUNDS!
        //
        // k TRANSACTIONS vs 2k OPERATIONS:
        // k=2 means 2 complete buy-sell pairs
        // But that requires 4 operations: [Buy₁, Sell₁, Buy₂, Sell₂]
        // So we need 2*k operations for k transactions
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        // explicit base cases can be written but they are all 0 anyway
        // so no point in doing extra work :

        // Fill DP table from last day to first day
        for (int i = n - 1; i >= 0; --i)
        {
            // Loop through operations 0 to 2k-1 (NOT 2k!)
            for (int transaction = 0; transaction < 2 * k; ++transaction)
            {
                // Even transaction = BUY operation
                if (!(transaction & 1))
                {
                    // Buy: pay price and move to next operation (transaction+1)
                    int canBuy = -prices[i] + dp[i + 1][transaction + 1];
                    // Skip: stay on same operation
                    int notBuy = dp[i + 1][transaction];
                    dp[i][transaction] = max(canBuy, notBuy);
                }
                // Odd transaction = SELL operation
                else
                {
                    // Sell: get price and move to next operation (transaction+1)
                    int canSell = prices[i] + dp[i + 1][transaction + 1];
                    // Skip: stay on same operation
                    int notSell = dp[i + 1][transaction];
                    dp[i][transaction] = max(canSell, notSell);
                }
            }
        }

        // Start from day 0, operation 0 (first buy)
        return dp[0][0];
    }
};

// Space Optimization :
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // Only need two 1D arrays instead of 2D table
        // curr[transaction] = max profit for current day with given operation
        // ahead[transaction] = max profit for next day with given operation
        //
        // SIZE: 2*k+1 (same reasoning as tabulation)
        // - Indices 0 to 2k-1: operations we compute
        // - Index 2k: base case
        vector<int> curr(2 * k + 1, 0), ahead(2 * k + 1, 0);

        // explicit base cases can be written but they are all 0 anyway
        // so no point in doing extra work :

        // Process from last day to first day
        for (int i = n - 1; i >= 0; --i)
        {
            // Loop through operations 0 to 2k-1 (NOT 2k!)
            // Same reason as tabulation: avoid accessing ahead[2k+1]
            for (int transaction = 0; transaction < 2 * k; ++transaction)
            {
                // Even transaction = BUY operation
                if (!(transaction & 1))
                {
                    // Buy: pay price, check next day's next operation
                    int canBuy = -prices[i] + ahead[transaction + 1];
                    // Skip: check next day's same operation
                    int notBuy = ahead[transaction];
                    curr[transaction] = max(canBuy, notBuy);
                }
                // Odd transaction = SELL operation
                else
                {
                    // Sell: get price, check next day's next operation
                    int canSell = prices[i] + ahead[transaction + 1];
                    // Skip: check next day's same operation
                    int notSell = ahead[transaction];
                    curr[transaction] = max(canSell, notSell);
                }
            }
            // Move current day's results to ahead for previous day's computation
            ahead = curr;
        }

        // Answer is at operation 0 (first buy) after processing all days
        return ahead[0];
    }
};
