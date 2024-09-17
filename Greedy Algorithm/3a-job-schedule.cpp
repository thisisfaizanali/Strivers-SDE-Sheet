#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        // we are looking to max profit
        // so sort profit in descending order
        sort(arr, arr + n, [](Job a, Job b)
             { return a.profit > b.profit; });
        // find the max deadline to create the size of the slot array
        int maxDeadline = 0;
        for (int i = 0; i < n; ++i)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        // create the slot array or the hash array
        vector<int> slots(maxDeadline + 1, -1);
        int jobsDone = 0, totalProfit = 0;
        for (int i = 0; i < n; ++i) // iterate for all jobs
        {
            for (int j = arr[i].dead; j > 0; --j) // to find a slot for the job
            {                                     // this loop can be optimized by dsu
                if (slots[j] == -1)               // if slot is empty
                {
                    slots[j] = arr[i].id; // fill it with the id or index
                    jobsDone++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {jobsDone, totalProfit};
    }
};