/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define eb emplace_back
#define all(p) p.begin(), p.end()
// #define idx size_t
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
private:
    void fun(int idx, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (target == 0) // base case
        {
            ans.push_back(ds); // store the valid subseq
            return;
        }
        for (int i = idx; i < candidates.size(); ++i)
        {
            if (i > idx && candidates[i] == candidates[i - 1])
            {
                // this is to skip duplicates
                continue;
            }
            if (candidates[i] > target)
            {
                // If the current candidate is greater than the remaining target, stop
                // Since the array is sorted, any further candidates will also be too large
                break;
            }
            ds.push_back(candidates[i]);                             // pick condition
            fun(i + 1, target - candidates[i], candidates, ds, ans); // move to i+1
            // cause we dont want to reuse the same element
            ds.pop_back(); // back track
        }
        // for loop will take care of the extra call that we used to do
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // ds to hold the subseq
        vector<int> ds;
        // ds to hold all valid subseq
        vector<vector<int>> ans;
        // to make it easier to skip duplicates
        sort(candidates.begin(), candidates.end());
        fun(0, target, candidates, ds, ans);
        return ans;
    }
};