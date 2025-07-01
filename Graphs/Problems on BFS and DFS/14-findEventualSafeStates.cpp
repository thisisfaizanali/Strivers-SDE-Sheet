/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Approach: DFS-based cycle detection :
// Any node that is part of or leads to a cycle is NOT safe!
// leetcode version :
class Solution
{
    bool dfsCheck(int node, vector<vector<int>> &graph, vector<int> &vis,
                  vector<int> &pathVis, vector<int> &checkSafe)
    {
        vis[node] = 1;       // Mark node as visited
        pathVis[node] = 1;   // Mark node as part of current DFS path
        checkSafe[node] = 0; // Initially assume node is unsafe

        for (auto &neighbour : graph[node])
        {
            if (!vis[neighbour])
            {
                // DFS on unvisited neighbor
                if (dfsCheck(neighbour, graph, vis, pathVis, checkSafe))
                    return true; // If a cycle is found, return true
            }
            else if (pathVis[neighbour])
            {
                // Found a back edge → cycle detected
                return true;
            }
        }

        // No cycle from this node → backtrack
        pathVis[node] = 0;
        checkSafe[node] = 1; // Mark node as safe
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> vis(n, 0), pathVis(n, 0), checkSafe(n, 0);
        vector<int> ans;

        // Run DFS from all unvisited nodes (for disconnected components too)
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
                dfsCheck(i, graph, vis, pathVis, checkSafe);
        }

        // All nodes marked as safe (1) are eventual safe states
        for (int i = 0; i < n; ++i)
        {
            if (checkSafe[i])
                ans.push_back(i);
        }

        return ans;
    }
};

// gfg version :
class Solution
{
private:
    bool dfsCheck(int node, vector<int> adj[], vector<int> &vis,
                  vector<int> &pathVis, vector<int> &checkSafe)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        checkSafe[node] = 0; // Assume unsafe initially

        for (auto &neighbour : adj[node])
        {
            if (!vis[neighbour])
            {
                if (dfsCheck(neighbour, adj, vis, pathVis, checkSafe))
                    return true; // Cycle detected in deeper call
            }
            else if (pathVis[neighbour])
            {
                return true; // Found a back edge → cycle
            }
        }

        pathVis[node] = 0;   // Backtrack for path tracking
        checkSafe[node] = 1; // No cycle → mark safe
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0), pathVis(V, 0), checkSafe(V, 0);
        vector<int> ans;

        // Check each node in the graph
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
                dfsCheck(i, adj, vis, pathVis, checkSafe);
        }

        // Collect all nodes marked as safe
        for (int i = 0; i < V; ++i)
        {
            if (checkSafe[i])
                ans.push_back(i);
        }

        return ans;
    }
};