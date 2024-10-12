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
    int minGroups(vector<vector<int>> &intervals)
    {
        // basically find the maximum number of non-overlapping intervals
        // LINE SWEEPING ALGORITHM
        int n = intervals.size();
        // for this algo events for intervals are required
        vector<pair<int, int>> events;
        for (auto &x : intervals)
        {
            events.pb({x[0], 1});
            events.pb({x[1] + 1, -1}); // to make end time inclusive -> +1
        }
        // sorting by time
        sort(all(events));

        int curr = 0, maxi = 0;
        for (auto &x : events)
        {
            curr += x.second;
            maxi = max(curr, maxi);
        }
        return maxi;
    }
};