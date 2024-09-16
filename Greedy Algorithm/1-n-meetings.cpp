#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct Meeting
    {
        int start;
        int end;
        int index;
    };
    static bool compare(Meeting m1, Meeting m2)
    {
        return m1.end < m2.end;
    }
    int maxMeetings(int n, int start[], int end[])
    {
        // vector of struct Meeting
        vector<Meeting> meetings(n);
        // initilaization
        for (int i = 0; i < n; ++i)
        {
            meetings[i] = {start[i], end[i], i + 1};
        }
        // sorting by end times in increasing order
        // custom comparator is used
        sort(meetings.begin(), meetings.end(), compare);

        int count = 1;
        int lastEnd = meetings[0].end;

        for (int i = 1; i < n; ++i)
        {
            if (meetings[i].start > lastEnd)
            {
                count++;
                lastEnd = meetings[i].end;
            }
        }
        return count;
    }
};
