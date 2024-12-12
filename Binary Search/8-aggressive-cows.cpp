/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr; }();
class Solution
{
public:
    int aggressiveCows(vector<int> &stalls, int k)
    {
        // k is number of cows
        // min dist between two cows should be maximum
        // bs on positions or distance
        sort(stalls.begin(), stalls.end()); // so sorting becomes necessary
        int low = 1;                        // min position
        int high = stalls.back() - stalls.front();
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            // mid is the potential min distance which we have to maximize
            if (feasible(stalls, mid, k))
                low = mid + 1; // maximise the value
            else
                high = mid - 1;
        }
        return high;
    }
    bool feasible(vector<int> &stalls, int minDistance, int k)
    {
        int lastPos = stalls[0];
        int cows = 1; // there is one cow at starting position
        for (int i = 0; i < stalls.size(); ++i)
        {
            if (stalls[i] - lastPos >= minDistance) /// ensure the min Distance aspect
            {
                lastPos = stalls[i];
                cows++; // cows can be placed
                if (cows == k)
                {
                    return true; // it is feasible
                }
            }
        }
        return false;
    }
};