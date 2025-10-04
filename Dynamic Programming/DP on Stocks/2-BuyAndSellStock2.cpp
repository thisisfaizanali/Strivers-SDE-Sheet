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
        // dp[i][buy] = max profit from index i onwards
        // buy=0 means we can sell (holding stock), buy=1 means we can buy
        // Initialize with -1 to indicate uncomputed states
        vector<vector<int>> dp(n, vector<int>(2, -1));

        // Start from day 0 in "can buy" state (buy=1)
        return solve(0, 1, prices, dp);
    }

private:
    int solve(int i, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        // Base case: reached end of array, no more profit possible
        if (i == prices.size())
            return 0;

        // If already computed, return memoized result
        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;

        if (buy) // State: we can buy
        {
            // Option 1: Buy stock at prices[i], pay the price, move to "can sell" state (buy=0)
            int willBuy = -prices[i] + solve(i + 1, 0, prices, dp);

            // Option 2: Don't buy, skip this day, stay in "can buy" state (buy=1)
            int notBuy = 0 + solve(i + 1, 1, prices, dp);

            // Take the maximum profit from both options
            profit = max(willBuy, notBuy);
        }
        else // State: we can sell (we're holding stock)
        {
            // Option 1: Sell stock at prices[i], earn the price, move to "can buy" state (buy=1)
            int sell = prices[i] + solve(i + 1, 1, prices, dp);

            // Option 2: Don't sell, keep holding, stay in "can sell" state (buy=0)
            int notSell = 0 + solve(i + 1, 0, prices, dp);

            // Take the maximum profit from both options
            profit = max(sell, notSell);
        }

        // Memoize and return the result
        return dp[i][buy] = profit;
    }
};

// Tabulation :
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        // dp[i][buy] = max profit from index i onwards
        // buy=0 means we can sell (holding stock), buy=1 means we can buy
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case: at day n (out of bounds), profit is 0
        dp[n][0] = dp[n][1] = 0;

        // Fill table from right to left (bottom-up approach)
        for (int i = n - 1; i >= 0; --i)
        {
            // Try both states: can buy (1) and can sell (0)
            for (int buy = 0; buy <= 1; ++buy)
            {
                if (buy == 1) // State: we can buy
                {
                    // Option 1: Buy stock at prices[i], then we can sell next (state 0)
                    int canBuy = -prices[i] + dp[i + 1][0];

                    // Option 2: Don't buy, stay in buy state (state 1)
                    int notBuy = 0 + dp[i + 1][1];

                    // Take maximum profit
                    dp[i][buy] = max(canBuy, notBuy);
                }
                else // State: we can sell (we're holding stock)
                {
                    // Option 1: Sell stock at prices[i], then we can buy next (state 1)
                    int canSell = prices[i] + dp[i + 1][1];

                    // Option 2: Don't sell, keep holding (state 0)
                    int notSell = 0 + dp[i + 1][0];

                    // Take maximum profit
                    dp[i][buy] = max(canSell, notSell);
                }
            }
        }

        // Return max profit starting from day 0 in "can buy" state
        return dp[0][1];
    }
};

// Space optimization :
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        // curr[buy] = current day's max profit for state 'buy'
        // ahead[buy] = next day's max profit for state 'buy'
        // Space optimization: only need current and next row, not entire 2D table
        vector<int> curr(2, 0), ahead(2, 0);

        // Base case: beyond last day, profit is 0
        ahead[0] = ahead[1] = 0;

        // Process days from right to left
        for (int i = n - 1; i >= 0; --i)
        {
            for (int buy = 0; buy <= 1; ++buy)
            {
                if (buy == 1) // Can buy state
                {
                    // Buy today and move to sell state tomorrow
                    int canBuy = -prices[i] + ahead[0];

                    // Skip buying, stay in buy state tomorrow
                    int notBuy = 0 + ahead[1];

                    curr[buy] = max(canBuy, notBuy);
                }
                else // Can sell state (holding stock)
                {
                    // Sell today and move to buy state tomorrow
                    int canSell = prices[i] + ahead[1];

                    // Don't sell, stay in sell state tomorrow
                    int notSell = 0 + ahead[0];

                    curr[buy] = max(canSell, notSell);
                }
            }

            // Move current day to ahead for next iteration
            ahead = curr;
        }

        // Return result from "can buy" state at day 0
        return ahead[1];
    }
};

// Four variable Space optimization :
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        // curr0 = current day, can sell state (holding stock)
        // curr1 = current day, can buy state
        // ahead0 = next day, can sell state
        // ahead1 = next day, can buy state
        // Further space optimization: replace arrays with individual variables
        int curr0, curr1, ahead0, ahead1;

        // Base case: beyond array bounds, profit is 0
        ahead0 = ahead1 = 0;

        // Process each day from right to left
        for (int i = n - 1; i >= 0; --i)
        {
            // Calculate "can buy" state (buy=1)
            // Option 1: Buy stock today (pay prices[i]), move to sell state tomorrow
            int canBuy = -prices[i] + ahead0;

            // Option 2: Don't buy, remain in buy state tomorrow
            int notBuy = 0 + ahead1;

            // Store max profit for "can buy" state
            curr1 = max(canBuy, notBuy);

            // Calculate "can sell" state (buy=0, we're holding)
            // Option 1: Sell stock today (earn prices[i]), move to buy state tomorrow
            int canSell = prices[i] + ahead1;

            // Option 2: Don't sell, remain in sell state tomorrow
            int notSell = 0 + ahead0;

            // Store max profit for "can sell" state
            curr0 = max(canSell, notSell);

            // Update ahead variables for next iteration (previous day)
            ahead0 = curr0, ahead1 = curr1;
        }

        // Return max profit starting from day 0 in "can buy" state
        return ahead1;
    }
};
