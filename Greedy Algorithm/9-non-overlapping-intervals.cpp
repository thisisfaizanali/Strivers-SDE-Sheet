/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        // similar to n meetings in one room
        //  min no of intervals to remove to make the rest non-overlapping
        int n = intervals.size();
        // let us find out the number of non-overlapping intervals
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        // sorted in increasing order of end times
        int count = 1; // no of overlapping intervals
        int lastend = intervals[0][1];
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][0] >= lastend) // non overlap condition; a>d
            {
                count++;
                lastend = intervals[i][1];
            }
        }
        // ans = total - non-overlapping count
        return n - count;
    }
};