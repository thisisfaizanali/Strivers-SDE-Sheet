/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define eb emplace_back
#define all(p) p.begin(), p.end()
#define idx size_t
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        // nums may have duplicates
        // return subsets without duplicates
        // any order
        sort(nums.begin(), nums.end()); // for better checking of duplicates
        vector<int> ds;                 // ds for storing subseq
        vector<vector<int>> ans;        // ans for storing valid subseq
        fun(0, nums, ds, ans);          // recursive function
        return ans;
    }

private:
    void fun(int idx, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
    {
        ans.push_back(ds); // to also include empty sets -> base case
        for (int i = idx; i < nums.size(); ++i)
        {
            if (i > idx && nums[i] == nums[i - 1])
            {
                continue; // skips duplicates at the same recurive level
            } // does not prevent at different levels the same number
            ds.push_back(nums[i]); // pick
            fun(i + 1, nums, ds, ans);
            ds.pop_back(); // not pick
        }
    }
};