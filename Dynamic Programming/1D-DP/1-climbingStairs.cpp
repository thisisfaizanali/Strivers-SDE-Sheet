/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// This problem is basically Fibonacci sequence :

// using Memoization :
class Solution
{
private:
    int helper(int n, vector<int> &memo)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 0;
        if (memo[n] != -1)
            return memo[n];
        return memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
    }

public:
    int climbStairs(int n)
    {
        vector<int> memo(n + 1, -1);
        return helper(n, memo);
    }
};

// Using Tabulation :
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};

// Space optimized DP :
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 0)
            return 1;
        int dp0 = 1;
        int dp1 = 1;
        for (int i = 2; i <= n; ++i)
        {
            int curr = dp0 + dp1;
            dp0 = dp1;
            dp1 = curr;
        }
        return dp1;
    }
};