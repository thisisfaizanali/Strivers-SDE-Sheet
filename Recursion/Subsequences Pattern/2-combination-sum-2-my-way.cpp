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
private:
    void fun(int index, vector<int> &candidates, int target, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (index >= candidates.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (candidates[index] <= target)
        {
            ds.push_back(candidates[index]);
            fun(index + 1, candidates, target - candidates[index], ds, ans);
            ds.pop_back();
        }
        // to avoid duplicates:
        int nextindex = index + 1;
        while (nextindex < candidates.size() && candidates[nextindex] == candidates[index])
        {
            nextindex++;
        }
        fun(nextindex, candidates, target, ds, ans);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(all(candidates));
        fun(0, candidates, target, ds, ans);
        return ans;
    }
};