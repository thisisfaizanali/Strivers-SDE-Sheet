/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // remember the non-overlapping condition
        //[a,b] and [c,d] are non-o iff c>b or a>d
        // we have to check for each intervals present in the array
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for (int i = 0; i < n - 1; ++i)
        {
            if (intervals[i][0] <= intervals[i + 1][0] && intervals[i][1] >= intervals[i + 1][0])
            // overlapping condition
            {
                intervals[i][0] = min(intervals[i][0], intervals[i + 1][0]);
                intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
                intervals.erase(intervals.begin() + i + 1);
                // erase operation is costly, it will take O(n)
                --i; // check again
                --n; // decreasing size is mandatory after using erase
            }
        }
        // because of erase and more checks runtime will be more
        // O(nlogn + n) -> theoretically
        return intervals;
    }
};