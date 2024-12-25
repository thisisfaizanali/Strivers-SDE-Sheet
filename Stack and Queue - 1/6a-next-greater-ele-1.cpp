/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        // this is my own approach
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans(m, -1);                 // to hold the answer
        set<int> s(nums1.begin(), nums1.end()); // for searching
        // for order :
        unordered_map<int, int> idxmap;
        for (int i = 0; i < m; ++i)
        {
            idxmap[nums1[i]] = i; // store the index
        }
        for (int i = 0; i < n; ++i)
        {
            if (s.find(nums2[i]) != s.end())
            {
                // present in set of nums1 elements
                // find nge
                int target = nums2[i];
                for (int j = i + 1; j < n; ++j)
                {
                    if (nums2[j] > target)
                    {
                        ans[idxmap[target]] = nums2[j];
                        break;
                    }
                }
            }
        }
        return ans;
    }
};