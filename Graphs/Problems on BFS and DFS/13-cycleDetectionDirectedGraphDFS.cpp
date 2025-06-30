/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis,
                  vector<int> &pathVis)
    {
        vis[node] = 1;     // Mark current node as visited
        pathVis[node] = 1; // Mark current node in current DFS path

        for (auto &neighbour : adj[node])
        {
            if (!vis[neighbour])
            {
                if (dfsCheck(neighbour, adj, vis, pathVis))
                    return true; // Cycle found in recursion
            }
            else if (pathVis[neighbour])
            {
                // If neighbour is visited and in current path → cycle detected
                return true;
            }
        }

        pathVis[node] = 0; // Backtrack: remove node from current DFS path
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // we use the concept of vis array + path vis array (to track path)

        // Build adjacency list from edge list :
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> vis(V, 0);     // vis array
        vector<int> pathVis(V, 0); // path vis array to track path

        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, adj, vis, pathVis))
                    return true; // Cycle detected
            }
        }

        return false;
    }
};
