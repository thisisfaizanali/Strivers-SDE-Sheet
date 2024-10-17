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
    // tc - O(2^n)
    // sc - O(2^n)
private:
    void fun(int index, int sum, vector<int> &arr, vector<int> &ans)
    {
        if (index >= arr.size())
        {
            // base condition
            ans.push_back(sum);
            return;
        }
        // we we either pick new element or dont pick
        fun(index + 1, sum + arr[index], arr, ans); // pick condition
        fun(index + 1, sum, arr, ans);              // not pick condition
    }

public:
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // print the sum of all subsets
        vector<int> ans;
        fun(0, 0, arr, ans); // recursive function is called
        return ans;
    }
};