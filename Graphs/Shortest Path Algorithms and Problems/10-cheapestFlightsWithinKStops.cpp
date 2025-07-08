/*++++++++++++++++++++++++++++++++++++++++++++++++++++++ Bismillah ++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Focus on stops : Not simple Dijkstra
    // No need of pq as stops increase by 1 :
    // BFS queue -> {stops, {current_node, current_cost}}

    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : flights)
            adj[e[0]].push_back({e[1], e[2]});

        vector<int> cost(n, 1e9);
        cost[src] = 0; // Cost to reach source is 0

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int currentCost = it.second.second;

            // Ignore paths that exceed the allowed number of stops :
            // You might be confused but this is okay :
            // We dont want to go beyond k + 1 which is k + 2
            // For the last time stops will go to k+1 and then stop
            // because essentially stops is actually number of flights : in reality : flights = stops + 1 : DON'T GET CONFUSED

            if (stops > k)
                continue;

            for (auto &neighbours : adj[node])
            {
                int neighbour = neighbours.first;
                int weight = neighbours.second;

                int newCost = currentCost + weight;

                // Relaxation: if a cheaper path to the neighbor is found
                if (newCost < cost[neighbour])
                {
                    cost[neighbour] = newCost;
                    q.push({stops + 1, {neighbour, newCost}});
                }
            }
        }

        return cost[dst] == 1e9 ? -1 : cost[dst];
    }
};
