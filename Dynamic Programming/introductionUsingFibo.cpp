/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Implements Fibonacci using Top-Down (Memoization), Bottom-Up (Tabulation), and Space-Optimized DP
class FibonacciDP
{
private:
    const int MOD = 1e9 + 7;
    vector<long long> memo; // For memoization

public:
    // Constructor
    FibonacciDP() {}

    // Method 1: Top-Down DP (Memoization)
    long long fibMemo(int n)
    {
        if (n <= 1)
            return n;

        if ((int)memo.size() <= n)
            memo.resize(n + 1, -1);

        if (memo[n] != -1)
            return memo[n];

        memo[n] = (fibMemo(n - 1) + fibMemo(n - 2)) % MOD;
        return memo[n];
    }

    // Method 2: Bottom-Up DP (Tabulation)
    long long fibTabu(int n)
    {
        if (n <= 1)
            return n;

        vector<long long> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        return dp[n];
    }

    // Method 3: Bottom-Up DP with Space Optimization (O(1) space)
    long long fibSpaceOpt(int n)
    {
        if (n <= 1)
            return n;

        long long prev2 = 0;
        long long prev1 = 1;

        for (int i = 2; i <= n; ++i)
        {
            long long curr = (prev1 + prev2) % MOD;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};