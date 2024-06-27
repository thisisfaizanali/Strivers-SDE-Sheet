class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // prices[i] = price on i day
        // maximize profit
        // buy when lowest price
        // sell when highest price
        // max element is first then skip it because you cant sell in the past
        // if the array is in descending order
        // return 0
        // if selling on i day
        // then buying it on the min of 1st to i-1
        int n = prices.size();
        int mini = prices[0];
        int maxprofit = 0;
        int cost;
        for (int i = 1; i < n; ++i)
        {
            cost = prices[i] - mini;
            maxprofit = max(maxprofit, cost);
            mini = min(mini, prices[i]);
        }
        return maxprofit;
    }
};