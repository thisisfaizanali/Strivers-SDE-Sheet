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
        // in-place -> swapping or something??
        // sorted -> two pointer??
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != nums[j])
            {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};
