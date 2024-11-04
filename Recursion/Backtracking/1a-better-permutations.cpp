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
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans; // will hold answer
        vector<int> ds;          // will hold the sequences
        vector<int> freq(nums.size(), 0);
        // freq array initialized to 0
        genpermute(ds, nums, ans, freq);
        return ans;
    }

private:
    void genpermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, vector<int> &freq)
    {
        if (ds.size() == nums.size())
        {
            // base case
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!freq[i]) // if value is 0
            {
                ds.push_back(nums[i]); // add value to ds
                freq[i] = 1;           // mark as taken
                genpermute(ds, nums, ans, freq);
                freq[i] = 0;   // unmark
                ds.pop_back(); // remove value
            }
        }
    }
};