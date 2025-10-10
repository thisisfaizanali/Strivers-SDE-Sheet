/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getLIS(vector<int> &arr)
    {
        int n = arr.size();            // Size of the input array
        vector<int> dp(n, 1), hash(n); // dp[i] = length of LIS ending at i; hash[i] = previous index in LIS
        int maxi = 1, lastIndex = 0;   // maxi = max LIS length found so far, lastIndex = index of last element in LIS

        // Outer loop: try to build LIS ending at each index i
        for (int i = 0; i < n; ++i)
        {
            hash[i] = i; // Initially, each element is its own predecessor

            // Inner loop: check all previous elements before i
            for (int p = 0; p < i; ++p)
            {
                // If arr[i] can extend the subsequence ending at arr[p]
                // and doing so gives a longer subsequence
                if (arr[i] > arr[p] && 1 + dp[p] > dp[i])
                {
                    dp[i] = 1 + dp[p]; // Update LIS length at i
                    hash[i] = p;       // Store index of previous element in the LIS
                }
            }

            // Track the index of the largest LIS length
            if (maxi < dp[i])
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the LIS sequence using hash[] array
        vector<int> lis;
        lis.emplace_back(arr[lastIndex]); // Start from the last element of LIS

        // Move backward following hash links until we reach the start
        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            lis.emplace_back(arr[lastIndex]);
        }

        // Reverse the sequence because we built it backwards
        reverse(lis.begin(), lis.end());

        // Return the LIS as a vector
        return lis;
    }
};
