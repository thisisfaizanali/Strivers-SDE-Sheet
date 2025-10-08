/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Use Buy and Sell Stock 2 code but add (-fee) whenever :
// you either buy or sell once

// Tabulation :
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; --i)
        {
            for (int b = 0; b <= 1; ++b)
            {
                if (b)
                {
                    int canBuy = -prices[i] + dp[i + 1][0];
                    int notBuy = dp[i + 1][1];
                    dp[i][b] = max(canBuy, notBuy);
                }
                else
                {
                    int canSell = prices[i] - fee + dp[i + 1][1];
                    int notSell = dp[i + 1][0];
                    dp[i][b] = max(canSell, notSell);
                }
            }
        }
        return dp[0][1];
    }
};

// Space optimization :
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> curr(2, 0), ahead(2, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            int canBuy = -prices[i] + ahead[0];
            int notBuy = ahead[1];
            curr[1] = max(canBuy, notBuy);

            int canSell = prices[i] - fee + ahead[1];
            int notSell = ahead[0];
            curr[0] = max(canSell, notSell);

            ahead = curr;
        }
        return ahead[1];
    }
};
