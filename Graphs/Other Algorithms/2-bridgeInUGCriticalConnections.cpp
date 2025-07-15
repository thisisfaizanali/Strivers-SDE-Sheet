/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int timer = 1; // global timer for timestamps

    void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low,
             vector<vector<int>> &adj, vector<vector<int>> &bridges)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer; // tin = time of entry, low = earliest reachable ancestor

        timer++; // increase timer value

        for (auto &neighbor : adj[node])
        {
            if (neighbor == parent)
                continue; // ignore the edge we came from

            if (!vis[neighbor])
            {
                dfs(neighbor, node, vis, tin, low, adj, bridges); // DFS deeper

                low[node] = min(low[node], low[neighbor]); // update low after child call

                if (low[neighbor] > tin[node]) // I cannot visit a lower ranked neighbour : so this is the only path
                                               // if i break this : i wil get more components : bridges
                    bridges.push_back({node, neighbor});
            }
            else
            {
                low[node] = min(low[node], tin[neighbor]); // back edge found, update low
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        // The ques wants Bridges :
        // Bridges : are those edges which removed lead to more components being formed :

        // TARJAN'S ALGO FOR FINDING BRIDGES :

        vector<vector<int>> adj(n);
        for (auto &edge : connections)
        {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        vector<int> vis(n, 0), tin(n, 0), low(n, 0); // tin = discovery time, low = earliest reachable ancestor
        vector<vector<int>> bridges;

        dfs(0, -1, vis, tin, low, adj, bridges); // start DFS from node 0

        return bridges;
    }
};
