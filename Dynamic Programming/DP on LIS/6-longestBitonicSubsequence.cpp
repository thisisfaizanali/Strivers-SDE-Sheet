/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        // lis[i] = longest strictly increasing subsequence ending at i
        // lds[i] = longest strictly decreasing subsequence starting at i
        vector<int> lis(n, 1), lds(n, 1);

        // LEFT TO RIGHT: Build LIS (increasing part)
        for (int i = 0; i < n; ++i)
        {
            // Check all elements before i
            for (int p = 0; p < i; ++p)
            {
                // If nums[p] < nums[i], we can extend the sequence
                if (nums[i] > nums[p] && 1 + lis[p] > lis[i])
                {
                    lis[i] = 1 + lis[p]; // Update with longer sequence
                }
            }
        }

        // RIGHT TO LEFT: Build LDS (decreasing part)
        for (int i = n - 1; i >= 0; --i)
        {
            // Check all elements after i
            for (int p = i + 1; p < n; ++p)
            {
                // If nums[i] > nums[p], we can extend the decreasing sequence
                if (nums[i] > nums[p] && 1 + lds[p] > lds[i])
                {
                    lds[i] = 1 + lds[p]; // Update with longer sequence
                }
            }
        }

        // Find the peak: position where lis[i] + lds[i] is maximum
        int maxLen = 0;
        for (int i = 0; i < n; ++i)
        {
            // Both parts must exist (> 1) for valid bitonic
            if (lis[i] > 1 && lds[i] > 1)
                // Subtract 1 because peak is counted in both lis and lds
                maxLen = max(maxLen, lis[i] + lds[i] - 1);
        }
        return maxLen;
    }
};
