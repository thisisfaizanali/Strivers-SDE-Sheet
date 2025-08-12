/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// 1. Memoization (Top-Down DP)
class Solution
{
private:
    // Recursive function with memoization
    // days: current day index (0-based)
    // last: task performed on the previous day (0..2) or 3 if no task restriction
    int memoization(int days, int last, vector<vector<int>> &arr, vector<vector<int>> &memo)
    {
        // Base case: first day → pick the best task not equal to 'last'
        if (days == 0)
        {
            int maxi = INT_MIN;
            for (int tasks = 0; tasks < 3; ++tasks)
            {
                if (tasks != last)
                    maxi = max(maxi, arr[0][tasks]);
            }
            return maxi;
        }

        // Return cached result if already computed
        if (memo[days][last] != -1)
            return memo[days][last];

        int maxi = INT_MIN;
        // Try all tasks except the one done the previous day
        for (int tasks = 0; tasks < 3; ++tasks)
        {
            if (last != tasks)
            {
                int points = arr[days][tasks] + memoization(days - 1, tasks, arr, memo);
                maxi = max(maxi, points);
            }
        }
        // Store and return result
        return memo[days][last] = maxi;
    }

public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> memo(n, vector<int>(4, -1));
        return memoization(n - 1, 3, arr, memo); // Start with 'last = 3' → no restriction
    }
};

// 2. Tabulation (Bottom-Up DP)
class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));

        // Base case: best score for day 0 when last task was X
        dp[0][0] = max(arr[0][1], arr[0][2]);
        dp[0][1] = max(arr[0][0], arr[0][2]);
        dp[0][2] = max(arr[0][0], arr[0][1]);
        dp[0][3] = max({arr[0][0], arr[0][1], arr[0][2]});

        // Fill DP table
        for (int days = 1; days < n; ++days)
        {
            for (int last = 0; last < 4; ++last)
            {
                for (int tasks = 0; tasks < 3; ++tasks)
                {
                    if (tasks != last)
                    {
                        dp[days][last] = max(dp[days][last], arr[days][tasks] + dp[days - 1][tasks]);
                    }
                }
            }
        }

        // Return best possible score with no restriction on the last day
        return dp[n - 1][3];
    }
};

// 3. Space Optimization (O(1) extra space beyond input)
class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> prev(4, 0), curr(4, 0);

        // Base case for day 0
        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);
        prev[3] = max({arr[0][0], arr[0][1], arr[0][2]});

        // Iteratively update for each day
        for (int day = 1; day < n; ++day)
        {
            for (int last = 0; last < 4; ++last)
            {
                curr[last] = 0;
                for (int task = 0; task < 3; ++task)
                {
                    if (task != last)
                    {
                        curr[last] = max(curr[last], arr[day][task] + prev[task]);
                    }
                }
            }
            prev = curr; // Move to next day
        }

        return prev[3];
    }
};
