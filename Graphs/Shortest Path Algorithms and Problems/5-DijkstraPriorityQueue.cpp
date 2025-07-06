/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Dijkstra does not work for negative weights on edges :
    // As it will lead to a infinite loop
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        // make adjacency list :
        vector<vector<pair<int, int>>> adj(V);
        for (auto &e : edges)
        {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // distance array :
        vector<int> distance(V, 1e9);
        // mark source as 0 :
        distance[src] = 0;

        // minHeap : {distance, node}
        // minHeap because : we want to find shortest path (priority is distance) :
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        minHeap.push({0, src}); // push distance from src to src and src

        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();

            int dist = top.first;  // distance from src to popped node
            int node = top.second; // popped node

            for (auto &neighbours : adj[node])
            {
                int neighbour = neighbours.first;
                int weight = neighbours.second;

                // greedily find shortest distance :
                // (Relax the edges)
                if (dist + weight < distance[neighbour])
                {
                    distance[neighbour] = dist + weight;
                    // push into heap when shortened :
                    minHeap.push({distance[neighbour], neighbour});
                }
            }
        }

        return distance; // stores answer
    }
};