/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// ---------------------- Memoization (Top-Down) ----------------------
// Think of this as:
// - Recursive call = go deeper towards the base case (stone 0)
// - Returned value from call = "bill so far" from bottom to that point
// - Add the current jump cost to that returned bill, and choose min of both paths
class Solution
{
private:
    int memoization(int index, vector<int> &height, vector<int> &memo)
    {
        if (index == 0) // base: cost to stand at first stone
            return 0;
        if (memo[index] != -1) // already computed bill
            return memo[index];

        // Option 1: come from previous stone
        int jumpOne = memoization(index - 1, height, memo) + abs(height[index] - height[index - 1]); // bill so far + cost of last jump

        // Option 2: come from stone two steps back
        int jumpTwo = INT_MAX;
        if (index > 1)
            jumpTwo = memoization(index - 2, height, memo) + abs(height[index] - height[index - 2]);

        return memo[index] = min(jumpOne, jumpTwo); // store min bill to reach this stone
    }

public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> memo(n + 1, -1);
        return memoization(n - 1, height, memo); // start from last stone and work backwards
    }
};

// ---------------------- Tabulation (Bottom-Up) ----------------------
// Think of this as:
// - dp[i] stores the "bill so far" to reach stone i from stone 0
// - Instead of going deeper like recursion, we already know bills for smaller i
// - For each i, bill = (bill to smaller stone) + (cost of last jump)
class Solution
{
public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0; // bill to reach stone 0 = 0

        for (int i = 1; i < n; ++i) // fill bills for each stone up to last
        {
            // Option 1: jump from previous stone
            int jumpOne = dp[i - 1] + abs(height[i] - height[i - 1]);

            // Option 2: jump from stone two steps back
            int jumpTwo = INT_MAX;
            if (i > 1)
                jumpTwo = dp[i - 2] + abs(height[i] - height[i - 2]);

            dp[i] = min(jumpOne, jumpTwo); // min bill to reach stone i
        }
        return dp[n - 1]; // bill to reach last stone
    }
};

// ---------------------- Space Optimized ----------------------
// Same "bill so far + last jump cost" logic as tabulation
// But we only need the last two bills at any point
class Solution
{
public:
    int minCost(vector<int> &height)
    {
        int n = height.size();
        int prev = 0;  // bill to reach stone i-1
        int prev2 = 0; // bill to reach stone i-2

        for (int i = 1; i < n; i++)
        {
            // Option 1: jump from previous stone
            int jumpOne = prev + abs(height[i] - height[i - 1]);

            // Option 2: jump from stone two steps back
            int jumpTwo = INT_MAX;
            if (i > 1)
                jumpTwo = prev2 + abs(height[i] - height[i - 2]);

            // min bill to reach stone i
            int curr = min(jumpOne, jumpTwo);

            // move forward: old prev becomes prev2, curr becomes prev
            prev2 = prev;
            prev = curr;
        }

        return prev; // bill to reach last stone
    }
};