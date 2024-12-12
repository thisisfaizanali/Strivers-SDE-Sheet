/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr; }();
class Solution
{
public:
    int kthElement(int k, vector<int> &arr1, vector<int> &arr2)
    {
        // similar to median ques of bs
        // here we do a split of k and n - k
        int n1 = arr1.size();
        int n2 = arr2.size();
        if (n1 > n2)
        {
            return kthElement(k, arr2, arr1);
        }
        // remember this :
        int low = max(0, k - n2);
        int high = min(k, n1);

        int left = k;
        while (low <= high)
        {
            int mid1 = low + ((high - low) >> 1);
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 < n1)
                r1 = arr1[mid1];
            if (mid2 < n2)
                r2 = arr2[mid2];
            if (mid1 - 1 >= 0)
                l1 = arr1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = arr2[mid2 - 1];
            if (l1 <= r2 && r1 >= l2)
            {
                return max(l1, l2); // as this will be the kth element
                // this stems from the split being of k and n- k
            }
            else if (l1 > r2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return -1;
    }
};
