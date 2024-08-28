/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // use set
        int n = nums.size();
        set<int> set;
        for (int i = 0; i < n; ++i)
        {
            set.insert(nums[i]);
        }
        int k = set.size();
        int j = 0;
        for (auto x : set)
        {
            nums[j++] = x;
        }
        return k;
    }
};
