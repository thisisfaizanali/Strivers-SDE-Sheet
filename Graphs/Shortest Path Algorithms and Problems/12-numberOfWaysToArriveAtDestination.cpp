/*++++++++++++++++++++++++++++++++++++++++++++++++++++++ Bismillah ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Question is essentially count the number of shortest paths :
    // Use ways array :
    // Use long long and long max for time
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &r : roads)
        {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        const int MOD = 1e9 + 7;

        // time[i] stores the shortest time to reach node i
        // Use long long to safely handle large weight sums
        vector<long long> time(n, LLONG_MAX);
        time[0] = 0;

        // ways[i] stores the number of shortest paths to reach node i
        vector<int> ways(n, 0);
        ways[0] = 1; // there is one way

        // Min-heap to process nodes in order of shortest current distance
        // long long for time :
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minHeap;
        minHeap.push({0, 0}); // {distance, node}

        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();

            long long currentTime = top.first;
            int node = top.second;

            for (auto &neighbours : adj[node])
            {
                int neighbour = neighbours.first;
                long long weight = neighbours.second;

                long long newTime = currentTime + weight;

                // If a shorter path is found
                if (newTime < time[neighbour])
                {
                    time[neighbour] = newTime;
                    minHeap.push({newTime, neighbour});

                    // Reset the number of ways as we found a shorter path
                    ways[neighbour] = ways[node];
                }

                // If another shortest path is found (same cost)
                else if (newTime == time[neighbour])
                {
                    // Increment the number of ways using modulo to avoid overflow
                    ways[neighbour] = (ways[neighbour] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};