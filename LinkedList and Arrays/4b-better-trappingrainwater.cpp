/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        // let's use pre-computation to find leftmax and leftmin
        // just like prefix sum. samjho!!
        // SC,TC = O(n),O(n)
        int prefix[n], suffix[n];
        prefix[0] = height[0];
        for (int i = 1; i < n; ++i)
        {
            prefix[i] = max(prefix[i - 1], height[i]);
        }
        suffix[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            suffix[i] = max(suffix[i + 1], height[i]);
        }
        int totalWaterTrapped = 0;
        for (int i = 0; i < n; ++i)
        {
            totalWaterTrapped += min(prefix[i], suffix[i]) - height[i];
        }
        return totalWaterTrapped;
    }
};