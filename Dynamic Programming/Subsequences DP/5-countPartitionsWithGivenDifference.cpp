/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Striver method: directly compute target subset sum = (totalSum + d) / 2
    // My method: iterate all possible s1, find s2 = totalSum - s1 and then check
    // using the condition : s1 - s2 == d
    // Here I have used my method :

    int countPartitions(vector<int> &arr, int d)
    {
        int n = arr.size();
        int totalSum = 0;
        for (int &x : arr)
            totalSum += x; // calculate total sum of array

        // dp[i][target] = number of subsets from index 0..i with sum = target
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));

        // every element can form subset with sum = 0 (by not taking anything)
        for (int i = 0; i < n; ++i)
            dp[i][0] = 1;

        // handle base case for first element
        if (arr[0] == 0)
            dp[0][arr[0]] = 2; // either take or don’t take the zero
        else if (totalSum >= arr[0])
            dp[0][arr[0]] = 1; // single element subset possible

        // build dp table
        for (int i = 1; i < n; ++i)
        {
            for (int target = 0; target <= totalSum; ++target)
            {
                int pick = 0, notPick = dp[i - 1][target];
                if (target >= arr[i])
                    pick = dp[i - 1][target - arr[i]];
                dp[i][target] = pick + notPick;
            }
        }

        int count = 0;
        // iterate over all possible subset sums s1
        for (int s1 = 0; s1 <= totalSum; ++s1)
        {
            int s2 = totalSum - s1;                // remaining elements form s2
            if (dp[n - 1][s1] && ((s1 - s2) == d)) // check difference condition
                count += dp[n - 1][s1];            // add number of ways to form s1
        }

        return count; // total valid partitions
    }
};
