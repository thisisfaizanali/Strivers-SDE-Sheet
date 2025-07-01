/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1; // Mark current node as visited

        for (auto &neighbour : adj[node])
        {
            if (!vis[neighbour])
            {
                dfs(neighbour, adj, vis, st);
            }
        }

        // Stack is used to store nodes in reverse of their finishing order.
        // This ensures that a node appears after all its dependencies in the final result.
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // Stack is used because of its LIFO nature :

        // Step 1: Build the adjacency list from edge list
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
            adj[edge[0]].push_back(edge[1]);

        vector<int> vis(V, 0); // Visited array to keep track of visited nodes
        stack<int> st;         // Stack to store the topological order

        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
                dfs(i, adj, vis, st);
        }

        // Nodes are popped from the stack to produce the topological order,
        // as the last finished node (no dependencies left) should come first in the ordering.
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
