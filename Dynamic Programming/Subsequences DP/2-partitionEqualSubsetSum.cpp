/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkTargetSum(vector<int> &nums, int sum)
    {
        int n = nums.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0)); // dp[i][j] = true if sum j can be formed using first i elements

        for (int i = 0; i < n; ++i)
            dp[i][0] = true; // sum 0 is always possible (empty subset)

        if (nums[0] <= sum)
            dp[0][nums[0]] = true; // base case: first element itself forms a subset

        // fill dp table
        for (int i = 1; i < n; ++i)
        {
            for (int target = 1; target <= sum; ++target)
            {
                bool notPick = dp[i - 1][target]; // exclude current element
                bool pick = false;
                if (target >= nums[i])
                    pick = dp[i - 1][target - nums[i]]; // include current element
                dp[i][target] = notPick || pick;        // take whichever is possible
            }
        }
        return dp[n - 1][sum]; // answer lies in last cell
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size(); // number of elements
        int totalSum = 0;    // total sum of array
        for (auto &x : nums)
            totalSum += x;

        if (totalSum & 1)
            return false; // odd total sum can't be split into two equal subsets

        // the two halves have to be equal : so check for subset sum == totalSum/2
        return checkTargetSum(nums, totalSum / 2);
    }
};
