/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    // Recursive + Memoization
    // Time: O(n*k), Space: O(n) + O(n) recursion stack
    int minCostMemo(int idx, vector<int> &height, int k, vector<int> &dp) {
        if (idx == 0)
            return 0;  // base case: no cost at start
        if (dp[idx] != -1)
            return dp[idx];

        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (idx - j >= 0) {
                int cost = minCostMemo(idx - j, height, k, dp) + abs(height[idx] - height[idx - j]);
                minCost = min(minCost, cost);
            }
        }
        return dp[idx] = minCost;
    }

    // Tabulation (Bottom-Up)
    // Time: O(n*k), Space: O(n)
    int minCostTab(vector<int> &height, int k) {
        int n = height.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;  // starting point

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    dp[i] = min(dp[i], dp[i - j] + abs(height[i] - height[i - j]));
                }
            }
        }
        return dp[n - 1];
    }

    /*
     * Space Optimization:
     * - Recurrence depends only on last 'k' states.
     * - We can store only k+1 dp values using a circular buffer (O(k) space).
     * - If k is small constant (e.g., k=2 in classic frog jump), space reduces to O(1).
     * - If k ~ n, space optimization gives no real benefit over O(n).
     */
};
