/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

/*
GFG : Undirected Graph Cycle
Approach : DFS
Idea  :  A cycle exists in an undirected graph if during BFS, we revisit a previously
visited node that is NOT the parent of the current node.
Time Complexity:  O(V + E)
    - V is the number of vertices.
    - E is the number of edges.
    - Each vertex and edge is visited at most once.
Space Complexity: O(V + E)
    - Adjacency list: O(V + E)
    - Visited array: O(V)
    - DFS recursion stack (worst case): O(V)
*/
class Solution
{
private:
    bool dfsCheck(int node, int parentNode, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[node] = 1; // mark current node as visited

        for (auto &neighbour : adj[node])
        {
            if (!vis[neighbour])
            {
                // Recur for unvisited neighbour
                if (dfsCheck(neighbour, node, adj, vis)) // node is neighbour and parent is node
                    return true;
            }
            // If neighbour is visited and not parent, a cycle is found
            else if (neighbour != parentNode)
                return true;
        }

        return false; // no cycle found in this path
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V); // adjacency list

        // Build the adjacency list from edge list
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0); // visited array

        // Run DFS from every unvisited node to handle disconnected components :
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, -1, adj, vis)) // starting nodes is i and parent is -1
                    return true;               // cycle detected
            }
        }

        return false; // no cycle found in any component
    }
};