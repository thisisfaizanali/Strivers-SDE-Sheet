/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Performs DFS on the original graph and stores nodes in a stack based on finishing time
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[node] = 1;

        for (auto &x : adj[node])
        {
            if (!vis[x])
            {
                dfs(x, vis, adj, st);
            }
        }

        // Push the node to stack after all its descendants are processed
        st.push(node);
    }

private:
    // DFS on the transposed graph to visit all nodes in a strongly connected component
    void dfsReverse(int node, vector<int> &vis, vector<vector<int>> &reverseGraph)
    {
        vis[node] = 1;

        for (auto &x : reverseGraph[node])
        {
            if (!vis[x])
                dfsReverse(x, vis, reverseGraph);
        }
    }

public:
    // Kosaraju's algorithm to find the number of strongly connected components in a directed graph
    // from gfg :
    int kosaraju(vector<vector<int>> &adj)
    {
        // DG means no DSU :

        int n = adj.size();

        vector<int> vis(n, 0);
        stack<int> st;

        // First DFS to fill the stack according to finish times
        // Similar to Topo Sort using Stack :
        // Helps in finding parent or entry points to SCC when used with vis array :
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i])
                dfs(i, vis, adj, st);
        }

        // Create a reversed (transposed) graph
        // Reversal alllows the splitting of SCCs :
        vector<vector<int>> reverseGraph(n);
        for (int i = 0; i < n; ++i)
        {
            for (auto &x : adj[i])
            {
                reverseGraph[x].push_back(i);
            }
        }

        // Reset visited array for second DFS
        fill(vis.begin(), vis.end(), 0);

        int count = 0;

        // Second DFS using stack order to count SCCs
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!vis[node])
            {
                count++;
                dfsReverse(node, vis, reverseGraph);
            }
        }

        return count;
    }
};