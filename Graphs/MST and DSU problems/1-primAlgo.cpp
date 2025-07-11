/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// gfg only :
class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Min-heap to pick the edge with the smallest weight at each step
        // Stores: {edge weight, destination node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0}); // Start with node 0 and weight 0

        int sum = 0;           // To store total weight of the MST
        vector<int> vis(V, 0); // to avoid cycles :

        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();

            int weight = top.first;
            int node = top.second;

            // Skip if the node is already included in the MST
            if (vis[node])
                continue;

            // Include the current node and add the edge weight to the MST total
            sum += weight;
            vis[node] = 1;

            // Traverse all adjacent nodes
            for (auto &x : adj[node])
            {
                int neighbour = x[0];  // Adjacent node
                int edgeWeight = x[1]; // Weight of edge to adjacent node

                // Only consider edges leading to unvisited nodes
                if (!vis[neighbour])
                {
                    minHeap.push({edgeWeight, neighbour});
                }
            }
        }

        // Return the total weight of the Minimum Spanning Tree
        return sum;
    }
};

// If you want the MST edges as well :
// int spanningTree(int V, vector<vector<int>> adj[])
// {
//     // {weight, node, parent} :
//     priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
//     minHeap.push({0, 0, -1}); // {wt, node, parent}

//     vector<int> vis(V, 0);
//     int sum = 0;

//     vector<pair<int, int>> mstEdges; // To store MST edges: {u, v}

//     while (!minHeap.empty())
//     {
//         auto [weight, node, parent] = minHeap.top();
//         minHeap.pop();

//         if (vis[node])
//             continue;

//         vis[node] = 1;
//         sum += weight;

//         // Store edge if it's not the starting node
//         if (parent != -1)
//             mstEdges.push_back({parent, node});

//         for (auto &x : adj[node])
//         {
//             int adjNode = x[0];
//             int edgeWeight = x[1];

//             if (!vis[adjNode])
//             {
//                 minHeap.push({edgeWeight, adjNode, node});
//             }
//         }
//     }
// }
