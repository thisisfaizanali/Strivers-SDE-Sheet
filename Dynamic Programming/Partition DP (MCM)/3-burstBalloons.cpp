/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoziation :
class Solution
{
private:
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        // Base case: when left index crosses right index, no balloons to burst
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = -1e9;

        // Try bursting each balloon 'k' between i and j last
        for (int k = i; k <= j; ++k)
        {
            // Cost = coins from bursting balloon 'k' last + coins from left + coins from right
            int cost = nums[i - 1] * nums[k] * nums[j + 1] // coins gained from bursting 'k' last
                       + solve(i, k - 1, nums, dp)         // solve left subarray
                       + solve(k + 1, j, nums, dp);        // solve right subarray

            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        // Add virtual balloons (value = 1) to both ends for easy boundary handling
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int c = nums.size(); // Total number of balloons including boundaries

        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));

        // Compute maximum coins from index 1 to c-2 (excluding added boundaries)
        return solve(1, c - 2, nums, dp);
    }
};

// Tabulation :
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        // Add 1 at both ends for boundary simplicity
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int c = nums.size();

        vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1e9));

        // Base case: when i > j, no balloons => 0 coins
        for (int i = 0; i <= c; ++i)
        {
            for (int j = 0; j <= c; ++j)
            {
                if (i > j)
                    dp[i][j] = 0;
            }
        }

        // Fill DP table in reverse order of 'i'
        // because smaller subproblems (larger i) are used to solve bigger ones
        for (int i = c - 2; i >= 1; --i)
        {
            for (int j = i; j <= c - 2; ++j)
            {
                // Try every possible 'k' as the last balloon to burst in range [i, j]
                for (int k = i; k <= j; ++k)
                {
                    int cost = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    dp[i][j] = max(cost, dp[i][j]);
                }
            }
        }

        // Final answer: max coins for entire array (excluding virtual boundaries)
        return dp[1][c - 2];
    }
};