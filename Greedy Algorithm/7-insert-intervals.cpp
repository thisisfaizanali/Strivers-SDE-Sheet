/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        // for two intervals[a,b] and [c,d]
        // non-overlapping iff -> c>b or a>d
        vector<vector<int>> ans; // to store the resultant intervals
        int n = intervals.size();
        int i = 0; // intervals is sorted
        //[a,b] === intervals[start,end] && [c,d]===newInterval[start,end]
        // there will be three parts: left, middle and right
        // step 1 : left part which is not overlapping
        while (i < n && newInterval[0] > intervals[i][1])
        {
            ans.emplace_back(intervals[i++]);
        }
        // step 2 : middle and overlapping part
        while (i < n && newInterval[1] >= intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        // add to ans
        ans.emplace_back(newInterval);
        // step 3 : right and non-overlapping part
        while (i < n)
        {
            ans.emplace_back(intervals[i++]);
        }
        return ans;
    }
};