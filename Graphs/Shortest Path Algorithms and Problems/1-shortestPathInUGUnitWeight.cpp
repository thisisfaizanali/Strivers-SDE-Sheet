/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        // Unweighted Graph (UG): No need for Topo Sort
        // Unit weights → use BFS with a queue

        // Distance array acts as both a distance tracker and visited marker
        int V = adj.size();

        vector<int> distance(V, 1e9); // Initialize all distances to "infinity"
        distance[src] = 0;            // Distance to source is 0

        queue<int> q;
        q.push(src);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &neighbour : adj[node])
            {
                // If a shorter path to neighbour is found
                if (distance[node] + 1 < distance[neighbour])
                {
                    distance[neighbour] = distance[node] + 1;
                    q.push(neighbour); // Enqueue only when distance is updated
                }
            }
        }

        // Replace unreachable nodes' distances with -1
        for (int i = 0; i < V; ++i)
        {
            if (distance[i] == 1e9)
                distance[i] = -1;
        }

        return distance;
    }
};
