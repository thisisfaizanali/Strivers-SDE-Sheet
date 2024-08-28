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
        // my brute force solution
        // 321/323 test cases
        // O(n2)
        int n = height.size();
        int totalWaterTrapped = 0;
        for (int i = 0; i < n; ++i)
        {
            int j = i;
            int left_max = 0;
            int right_max = 0;
            while (j >= 0)
            {
                left_max = max(left_max, height[j]);
                j--;
            }
            j = i;
            while (j < n)
            {
                right_max = max(right_max, height[j]);
                j++;
            }
            totalWaterTrapped += min(left_max, right_max) - height[i];
        }
        return totalWaterTrapped;
    }
};