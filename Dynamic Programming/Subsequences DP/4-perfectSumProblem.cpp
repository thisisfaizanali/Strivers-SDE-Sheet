/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1)); // dp[idx][sum] = ways to form 'sum' using elements[0..idx]
        return solve(n - 1, target, arr, dp);
    }

private:
    int solve(int idx, int sum, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (sum == 0)
            return 1; // empty subset always possible

        if (idx == 0)
        {
            if (arr[0] == 0)
                return 2; // pick or not pick zero : picking and not picking are both valid : so 1 + 1 = 2;
            else if (arr[0] <= sum)
                return 1; // one way to form sum
            else
                return 0; // not possible
        }

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        // Option 1: do not pick current element
        int notPick = solve(idx - 1, sum, arr, dp);

        // Option 2: pick current element (if possible)
        int pick = 0;
        if (sum >= arr[idx])
            pick = solve(idx - 1, sum - arr[idx], arr, dp);

        // Store and return result
        return dp[idx][sum] = pick + notPick;
    }
};

// Tabulation :
class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        // Base cases
        for (int i = 0; i < n; ++i)
            dp[i][0] = 1; // empty subset always possible
        if (arr[0] == 0)
            dp[0][0] = 2; // pick or not pick zero : picking and not picking are both valid : so 1 + 1 = 2;
        else if (arr[0] <= target)
            dp[0][arr[0]] = 1;

        // Tabulation
        for (int i = 1; i < n; ++i)
        {
            for (int sum = 0; sum <= target; ++sum)
            {
                int notPick = dp[i - 1][sum];
                int pick = 0;
                if (sum >= arr[i])
                    pick = dp[i - 1][sum - arr[i]];
                dp[i][sum] = pick + notPick;
            }
        }
        return dp[n - 1][target];
    }
};

// Space optimization :
class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        // Base cases
        prev[0] = 1; // one way for sum = 0
        if (arr[0] == 0)
            prev[0] = 2; // pick or not pick zero : picking and not picking are both valid : so 1 + 1 = 2;
        else if (arr[0] <= target)
            prev[arr[0]] = 1;

        // Space optimized tabulation
        for (int i = 1; i < n; ++i)
        {
            fill(curr.begin(), curr.end(), 0); // reset for new row
            for (int sum = 0; sum <= target; ++sum)
            {
                int notPick = prev[sum];
                int pick = 0;
                if (sum >= arr[i])
                    pick = prev[sum - arr[i]];
                curr[sum] = pick + notPick;
            }
            prev = curr;
        }

        return prev[target];
    }
};
