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
    // recursive function
    void fun(int idx, int target, vector<int> &candidates, vector<int> &ds, vector<vector<int>> &ans)
    {
        // base case
        if (idx >= candidates.size())
        {
            if (target == 0) // condition for valid subseq
            {
                ans.push_back(ds);
            }
            return;
        }
        if (candidates[idx] <= target) // can only pick is this is true
        {
            ds.push_back(candidates[idx]);                           // pick
            fun(idx, target - candidates[idx], candidates, ds, ans); // pick
            // idx remains same because elem can be selected infinite times
            ds.pop_back(); // for not pick, back-tracking
        }
        fun(idx + 1, target, candidates, ds, ans);
        // idx increases by 1 if we are not picking
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // ds to store subseq
        vector<int> ds;
        // ds to store vector of valid subseq
        vector<vector<int>> ans;
        fun(0, target, candidates, ds, ans);
        return ans;
    }
};