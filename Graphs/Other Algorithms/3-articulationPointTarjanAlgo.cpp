/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int timer = 1; // Global timer to assign discovery times (tin)

    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin,
             vector<int> &low, vector<int> adj[], vector<int> &mark)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++; // Set discovery and low time

        int child = 0; // Count of children in DFS tree (important for root node case)

        for (auto &neighbour : adj[node])
        {
            if (neighbour == parent)
                continue; // Ignore the edge to parent (it's not a back edge)

            if (!vis[neighbour])
            {
                dfs(neighbour, node, vis, tin, low, adj, mark); // Recurse into unvisited neighbour

                low[node] = min(low[node], low[neighbour]); // Update low after recursion

                // Articulation point condition (non-root):
                // If the subtree rooted at 'neighbour' can't reach above 'node' : that means AP :
                if (low[neighbour] >= tin[node] && parent != -1)
                    mark[node] = 1;

                child++; // Count children of current node
            }
            else
            {
                // Back edge found → update low[node] via tin[neighbour]
                low[node] = min(low[node], tin[neighbour]);
            }
        }

        // Root node special case: if it has 2 or more children, it's an articulation point
        if (parent == -1 && child > 1)
            mark[node] = 1;
    }

public:
    // Uses Tarjan Algo :
    // AP : nodes when removed produce more components :
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0), tin(V, 0), low(V, 0);
        vector<int> mark(V, 0); // contains nodes marked as articulation points

        // Run DFS for each component
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, tin, low, adj, mark);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; ++i)
        {
            if (mark[i])
                ans.push_back(i);
        }

        if (ans.empty())
            return {-1}; // No articulation point found

        return ans;
    }
};