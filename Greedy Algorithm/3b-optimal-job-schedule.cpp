#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// DSU class
class DSU
{
private:
    vector<int> parent;

public:
    DSU(int n)
    {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // Initialize parent[i] = i
    }

    // Find the representative of the set containing x
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Union of the sets containing x and y
    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            parent[rootX] = rootY; // Union operation
        }
    }
};

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // Step 1: Sort jobs based on profit in decreasing order
        sort(arr, arr + n, [](Job a, Job b)
             { return a.profit > b.profit; });

        // Step 2: Find the maximum deadline to set the DSU
        int maxDeadline = 0;
        for (int i = 0; i < n; ++i)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        // Initialize DSU with slots up to maxDeadline
        DSU dsu(maxDeadline);

        // Variables to store the number of jobs done and total profit
        int jobCount = 0, totalProfit = 0;

        // Step 3: Schedule the jobs
        for (int i = 0; i < n; ++i)
        {
            int availableSlot = dsu.find(arr[i].dead); // Find the latest available slot before or on deadline
            if (availableSlot > 0)
            {
                dsu.unionSet(availableSlot, availableSlot - 1); // Mark this slot as filled and union with the previous slot
                jobCount++;
                totalProfit += arr[i].profit;
            }
        }

        return {jobCount, totalProfit};
    }
};
