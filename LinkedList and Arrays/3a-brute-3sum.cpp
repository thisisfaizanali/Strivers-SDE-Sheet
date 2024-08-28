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
        // tle exceeded at 310/313 test case
        int n = nums.size();
        set<vector<int>> st;
        for (int i = 0; i < n; ++i)
        {
            set<int> hashset;
            for (int j = i + 1; j < n; ++j)
            {
                int target = -(nums[i] + nums[j]);
                if (hashset.find(target) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // add element to set
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};