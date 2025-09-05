/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDifference(vector<int> &arr)
    {
        // Pre-requisite : partition subset problem
        // DP table -> dp[i][target] = true if subset sum = target possible using first i+1 elements
        int n = arr.size();

        int totalSum = 0;
        for (int &x : arr)
            totalSum += x;

        vector<vector<char>> dp(n, vector<char>(totalSum + 1, 0));
        // Base cases
        for (int i = 0; i < n; i++)
            dp[i][0] = 1; // sum = 0 is always possible

        if (arr[0] <= totalSum)
            dp[0][arr[0]] = 1; // first element alone can form subset sum

        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target <= totalSum; target++)
            {
                bool notPick = dp[i - 1][target]; // don't take arr[i]
                bool pick = false;
                if (target >= arr[i])
                    pick = dp[i - 1][target - arr[i]]; // take arr[i]

                dp[i][target] = pick || notPick;
            }
        }

        // Only check sums up to totalSum/2 (symmetry)
        int mini = 1e9;
        for (int s1 = 0; s1 <= totalSum / 2; s1++)
        {
            if (dp[n - 1][s1]) // if subset sum s1 is possible
            {
                int s2 = totalSum - s1;
                mini = min(mini, abs(s1 - s2));
            }
        }

        return mini;
    }
};
