class Solution
{

public:
    int minCoins(vector<int> &coins, int sum)
    {
        // will not work for all cases and surely fail when submitting
        // as it is greedy
        // correct solution is using DP
        if (sum == 0)
            return 0;
        sort(coins.begin(), coins.end());
        int count = 0;
        for (int i = 0; i < coins.size(); ++i)
        {
            while (sum >= coins[i])
            {
                sum -= coins[i];
                count++;
            }
        }
        if (sum != 0)
            return -1;
        return count;
    }
};