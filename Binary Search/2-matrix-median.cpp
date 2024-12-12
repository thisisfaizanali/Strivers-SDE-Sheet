/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr; }();
class Solution
{
public:
    int median(vector<vector<int>> &mat)
    {
        // number of rows and cols is odd
        // number  of els is also odd
        // median will also be at odd position
        int m = mat.size();    // rows
        int n = mat[0].size(); // cols
        int low = INT_MAX, high = INT_MIN;
        // low will be min el and high max of arr
        // since median will have equal el on both left and right
        for (int i = 0; i < m; ++i)
        {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][n - 1]);
        }
        int reqPosition = (m * n) / 2; // for 0-based index, median will be here
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            // the idea is to find count of nums <=mid
            int count = smallCount(mat, mid, m, n);
            if (count <= reqPosition)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
    int smallCount(vector<vector<int>> &mat, int mid, int m, int n)
    {
        int count = 0;

        // For each row, use binary search to count the number of elements <= mid
        for (int i = 0; i < m; ++i)
        {
            // upper_bound gives the first element greater than 'mid'
            // The difference between upper_bound and the beginning of the row gives the count of elements <= mid
            count += (upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin());
        }
        return count;
    }
};