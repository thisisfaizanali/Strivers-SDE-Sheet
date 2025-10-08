/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Tabulation :
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0)); // dp[i][b]: max profit from day i onwards, b=1 (can buy), b=0 (can sell)
        // Need n+2 size because we access dp[i+2] when selling (cooldown constraint)
        for (int i = n - 1; i >= 0; --i) // Iterate backwards from last day to first
        {
            for (int b = 0; b <= 1; ++b) // b=0 (holding stock, can sell), b=1 (no stock, can buy)
            {
                if (b) // State: Can buy
                {
                    int canBuy = -prices[i] + dp[i + 1][0]; // Buy today, transition to "can sell" state tomorrow
                    int notBuy = dp[i + 1][1];              // Skip buying, stay in "can buy" state tomorrow
                    dp[i][b] = max(canBuy, notBuy);         // Take maximum of two choices
                }
                else // State: Can sell (holding stock)
                {
                    //  after selling cannot buy on the next day : so go to i + 2 day instead of i + 1 day :
                    int canSell = prices[i] + dp[i + 2][1]; // Sell today, cooldown enforced: can only buy from day i+2
                    int notSell = dp[i + 1][0];             // Don't sell, stay in "can sell" state tomorrow
                    dp[i][b] = max(canSell, notSell);       // Take maximum of two choices
                }
            }
        }
        return dp[0][1]; // Start from day 0 in "can buy" state (no stock initially)
    }
};

// Space optimization and removal of inner loop :
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> curr(2, 0), ahead1(2, 0), ahead2(2, 0); // curr: current day, ahead1: i+1 day, ahead2: i+2 day
        // Only need to track 3 days at a time due to cooldown constraint
        for (int i = n - 1; i >= 0; --i) // Iterate backwards from last day
        {
            int canBuy = -prices[i] + ahead1[0]; // Buy today, can sell tomorrow
            int notBuy = ahead1[1];              // Skip buying today, can buy tomorrow
            curr[1] = max(canBuy, notBuy);       // Store result for "can buy" state
            //  after selling cannot buy on the next day : so go to i + 2 day instead of i + 1 day :
            int canSell = prices[i] + ahead2[1]; // Sell today, cooldown: can buy from day i+2
            int notSell = ahead1[0];             // Don't sell today, can sell tomorrow
            curr[0] = max(canSell, notSell);     // Store result for "can sell" state
            ahead2 = ahead1;                     // Shift: day i+1 becomes day i+2
            ahead1 = curr;                       // Shift: current day becomes day i+1
        }
        return ahead1[1]; // Return max profit starting from day 0 in "can buy" state
    }
};
