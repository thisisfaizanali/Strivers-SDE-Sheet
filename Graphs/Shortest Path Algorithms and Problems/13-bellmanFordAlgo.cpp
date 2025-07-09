/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Bellman Ford works for DG :
    // Convert UG to DG if needed
    // DP category
    // Can detect negative cycles and works for negative values
    // unlike Dijkstra
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> distance(V, 1e8);
        distance[src] = 0;

        // V - 1 iterations : [0, V-1]
        // Relax the edges :
        for (int i = 0; i < V - 1; ++i)
        {
            for (auto &x : edges)
            {
                int u = x[0];
                int v = x[1];
                int w = x[2];

                if (distance[u] != 1e8 && distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                }
            }
        }

        // If we can relax more than V - 1 times : negative cycle
        // as for negative values we can keep on shortening values :
        for (auto &x : edges)
        {
            int u = x[0];
            int v = x[1];
            int w = x[2];

            if (distance[u] != 1e8 && distance[u] + w < distance[v])
            {
                return {-1}; // negative cycle detected
            }
        }

        return distance;
    }
};