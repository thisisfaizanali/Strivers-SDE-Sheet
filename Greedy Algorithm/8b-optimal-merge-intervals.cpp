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
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        // create ans to store the final intervals
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
        {
            // if the ans vector is empty
            // or start of interval[i] > the end time of last interval store in ans
            if (ans.empty() || intervals[i][0] > ans.back()[1])
            {
                // store that array
                // fills the array || non-overlapping intervals are put in as they are atq
                ans.emplace_back(intervals[i]);
            }
            else
            {
                // overlapping condition
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
                // The first interval (arr[i]) that overlaps with the last interval in ans will always have a start that is less than or equal to the end of the last interval.
                // Therefore, the start of the last interval in ans is already the minimum it needs to be, as it was derived from the first interval we considered.
            }
        }
        return ans;
    }
};