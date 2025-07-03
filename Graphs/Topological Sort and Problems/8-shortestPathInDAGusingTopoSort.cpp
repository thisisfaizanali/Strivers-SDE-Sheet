/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void topoSort(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1; // Mark current node as visited

        for (auto &neighbours : adj[node]) // Traverse all adjacent nodes
        {
            int neighbour = neighbours.first;
            if (!vis[neighbour]) // If adjacent node is not visited
            {
                topoSort(neighbour, adj, vis, st); // Recurse on the adjacent node
            }
        }

        st.push(node); // Push current node to stack after visiting all neighbors
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        // Topo Sort gives the right order to calculate distances
        // as all dependencies are handled first

        // Step 1: Build adjacency list from edges
        vector<vector<pair<int, int>>> adj(V); // Each node has list of {neighbor, weight}
        for (auto &edge : edges)
            adj[edge[0]].push_back({edge[1], edge[2]}); // Add directed edge

        // Step 2: Perform Topological Sort
        vector<int> vis(V, 0); // Visited array
        stack<int> st;         // Stack to store topological order
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])                   // If node is not visited
                topoSort(i, adj, vis, st); // Perform DFS from node
        }

        // Step 3: Initialize distances with 1e9 as INT_MAX may lead to overflow :
        vector<int> distance(V, 1e9); // Distance array

        // Set the distance to the source node (node 0) as 0
        // This marks the starting point for shortest path calculation
        // All other nodes are considered unreachable (infinity) until proven reachable from node 0
        distance[0] = 0;

        // Step 4: Process nodes in topological order
        while (!st.empty())
        {
            int node = st.top(); // Get next node in order
            st.pop();

            if (distance[node] != 1e9)
            {
                for (auto &neighbours : adj[node]) // Traverse neighbors
                {
                    int neighbour = neighbours.first;
                    int wt = neighbours.second;

                    // Relax the edge if a shorter path is found :
                    if (distance[node] + wt < distance[neighbour])
                        distance[neighbour] = distance[node] + wt;
                }
            }
        }

        // Step 5: Replace unreachable node's distances with -1
        for (int i = 0; i < V; ++i)
        {
            if (distance[i] == 1e9)
                distance[i] = -1; // Mark unreachable nodes
        }

        return distance; // Return final shortest distances
    }
};
