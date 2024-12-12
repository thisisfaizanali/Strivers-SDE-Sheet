/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr; }();
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        // perform bs on shorter array
        if (n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n1;
        int left = (n1 + n2 + 1) >> 1; // number of elements required on left
        int n = n1 + n2;               // total size
        while (low <= high)
        {
            int mid1 = low + ((high - low) >> 1);
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            // boundary checks
            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];
            // solution posssible when : (the bs part)
            if (l1 <= r2 && l2 <= r1)
            {
                if (n & 1) // if no of els is odd
                {
                    return max(l1, l2); // ans
                }
                else
                {
                    // if even then :
                    return (double)((max(l1, l2) + min(r1, r2))) / 2.0;
                }
            }
            else if (l1 > r2)
            {
                high = mid1 - 1;
                // l1 value is too big, reduce it
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return 0.0; // default return value
    }
};
