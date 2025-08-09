/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int rob1(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);

        dp[0] = nums[0]; // Base case: rob first house

        for (int i = 1; i < n; ++i)
        {
            int pick = nums[i];
            if (i > 1)
                pick += dp[i - 2]; // If picking current house, add dp[i-2]

            int notPick = dp[i - 1]; // Skip current house, take previous max

            dp[i] = max(pick, notPick); // Maximize between picking and skipping
        }
        return dp[n - 1]; // Result stored in last element
    }

public:
    /*
        Since the houses are arranged in a circle,
        we cannot rob both the first and last house simultaneously.
        Approach:
        - Consider two scenarios:
            1. Rob houses from 1 to n-1 (exclude first house)
            2. Rob houses from 0 to n-2 (exclude last house)
        - Solve each using the linear house robber function rob1
        - Return the maximum of the two results
    */
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1) // Only one house, rob it
            return nums[0];

        if (n == 0) // No houses to rob
            return 0;

        vector<int> temp1, temp2;

        // Prepare the two linear sequences excluding first or last house
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                temp1.push_back(nums[i]); // Houses [1..n-1]
            if (i != n - 1)
                temp2.push_back(nums[i]); // Houses [0..n-2]
        }

        // Solve both linear problems
        int val1 = rob1(temp1);
        int val2 = rob1(temp2);

        return max(val1, val2); // Return maximum robbed amount
    }
};
