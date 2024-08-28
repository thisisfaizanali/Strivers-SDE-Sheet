/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
        {
            // remove duplicates :
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // sorted array -> two pointer;
            int j = i + 1; // left pointer
            int k = n - 1; // right pointer
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.emplace_back(temp);
                    j++;
                    k--;
                    // duplicate check for j and k
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};