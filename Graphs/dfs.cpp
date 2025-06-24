/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfsHelper(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &dfs)
    {
        vis[node] = 1;          // mark as visited
        dfs.emplace_back(node); // store in the result vector
        // traverse all neighbours :
        for (int neighbour : adj[node])
        {
            // If the neighbour has not been visited yet, explore it recursively
            if (!vis[neighbour])
            {
                dfsHelper(neighbour, adj, vis, dfs);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>> &adj)
    {
        // V is the number of nodes or vertices :
        int V = adj.size();
        vector<int> vis(V, 0);       // visited array
        vector<int> dfs;             // to store the answer
        dfsHelper(0, adj, vis, dfs); // starting node is 0
        return dfs;
    }
};