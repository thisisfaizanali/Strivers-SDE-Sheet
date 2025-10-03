/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// This greedy but its follow ups are DP :
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = 1e9; // Initialize to large value so first price will update it
        int maxProfit = 0;  // Start with 0 profit (in case we can't make any profit)

        for (int &price : prices)
        {
            minPrice = min(minPrice, price);              // Track the lowest price seen so far (best buy point)
            maxProfit = max(maxProfit, price - minPrice); // Calculate profit if selling today at price p, after buying at minPrice
        }

        return maxProfit; // Return the maximum profit achievable
    }
};
