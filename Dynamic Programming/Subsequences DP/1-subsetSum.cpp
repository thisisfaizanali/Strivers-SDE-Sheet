/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class Solution
{
private:
    bool solve(int i, int target, vector<vector<int>> &dp, vector<int> &arr)
    {
        if (target == 0) // base case: subset with sum 0 always exists (empty subset)
            return true;
        if (i == 0) // base case: only one element left to check
            return arr[i] == target;
        if (dp[i][target] != -1) // return cached result if already computed
            return dp[i][target];

        bool notPick = solve(i - 1, target, dp, arr); // option 1: skip current element
        bool pick = false;
        if (target >= arr[i]) // option 2: pick current element (if it does not exceed target)
            pick = solve(i - 1, target - arr[i], dp, arr);

        return dp[i][target] = pick || notPick; // store and return result
    }

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        // dp[i][t] stores result for subproblem (can we form t using elements 0..i)
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(n - 1, sum, dp, arr); // start from last index and full sum
    }
};

// Tabulation :
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        // dp[i][t] = true if we can form sum t using elements 0..i
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; ++i)
            dp[i][0] = true; // base case: sum 0 can always be formed

        // without if wil lead to out of bounds errro : if arr[0] > sum :
        if (arr[0] <= sum)
            dp[0][arr[0]] = true; // base case: first element alone can form its own value (if within sum)

        // fill the table
        for (int i = 1; i < n; ++i)
        {
            for (int target = 1; target <= sum; ++target)
            {
                bool notPick = dp[i - 1][target]; // skip current element
                bool pick = false;
                if (target >= arr[i]) // include current element if allowed
                {
                    pick = dp[i - 1][target - arr[i]];
                }
                dp[i][target] = pick | notPick; // subset exists if either option works
            }
        }

        return dp[n - 1][sum]; // final answer: can we form 'sum' using all elements
    }
};

// Space-Optimization :
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        // prev = dp row for i-1, curr = dp row for i
        vector<bool> prev(sum + 1, 0), curr(sum + 1, 0);

        prev[0] = curr[0] = true; // sum 0 is always possible

        // without if wil lead to out of bounds errro : if arr[0] > sum :
        if (arr[0] <= sum)
            prev[arr[0]] = true; // base case: first element alone can form its own value (if within sum)

        for (int i = 1; i < n; ++i)
        {
            for (int target = 1; target <= sum; ++target)
            {
                bool notPick = prev[target]; // skip current element
                bool pick = false;
                if (target >= arr[i]) // include current element if allowed
                {
                    pick = prev[target - arr[i]];
                }
                curr[target] = pick | notPick; // update current row
            }
            prev = curr; // shift current row to previous for next iteration
        }

        return prev[sum]; // answer stored in last row
    }
};
