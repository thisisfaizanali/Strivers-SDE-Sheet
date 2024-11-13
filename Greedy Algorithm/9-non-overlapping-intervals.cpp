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
        // ans = num of overlapping intervals
        // given ques just use b>c condition and else update end
        int n = intervals.size();
        int count = 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        int end = intervals[0][1]; // end of first interval
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][0] < end)
            {
                count++;
            }
            else
            {
                end = intervals[i][1];
            }
        }
        return count;
    }
};