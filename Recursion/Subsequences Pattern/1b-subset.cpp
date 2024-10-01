/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        // nums has unique elements
        // return all possible subsets
        // we can have 2^n no of sets in subset
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds; // will hold elements of subset
        subsetRecursion(0, nums, ds, ans);
        return ans;
    }

private:
    void subsetRecursion(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (idx >= nums.size())
        {
            ans.emplace_back(ds);
            return;
        }
        ds.emplace_back(nums[idx]);
        subsetRecursion(idx + 1, nums, ds, ans);
        ds.pop_back();
        subsetRecursion(idx + 1, nums, ds, ans);
    }
};