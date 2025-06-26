/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

/*
GFG : Undirected Graph Cycle
Approach : BFS
Idea  :  A cycle exists in an undirected graph if during BFS, we revisit a previously
visited node that is NOT the parent of the current node.
Time Complexity: O(V + E)
-Each node and edge is processed once.
Space Complexity: O(V + E)*/
class Solution
{
private:
    bool bfsCheck(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        queue<pair<int, int>> q;
        // queue : {node, parentNode} :
        q.push({node, -1}); // Start with parent = -1
        vis[node] = 1;

        while (!q.empty())
        {
            int parent = q.front().second;
            int node = q.front().first;
            q.pop();

            for (auto &neighbour : adj[node])
            {
                if (!vis[neighbour])
                {
                    vis[neighbour] = 1;
                    q.push({neighbour, node});
                }
                // Main logic: if a visited neighbour is not the parent → cycle
                else if (vis[neighbour] && parent != neighbour)
                    return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Build adjacency list from edge list
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Visited array :
        vector<int> vis(V, 0);

        // Graph may have multiple components
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i] && bfsCheck(i, adj, vis))
                return true;
        }
        return false;
    }
};
