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
        vector<vector<int>> ans; // to store permutations
        genpermute(0, nums, ans);
        return ans;
    }

private:
    void genpermute(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        // base case
        if (index >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); ++i)
        {
            swap(nums[index], nums[i]);       // swap with the next options
            genpermute(index + 1, nums, ans); // go to the next index and call
            swap(nums[index], nums[i]);       // backtrack by swapping
        }
    }
};