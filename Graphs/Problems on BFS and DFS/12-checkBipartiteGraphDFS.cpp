/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// leetcode version :
class Solution
{
private:
    bool dfsCheck(int node, int colorValue, vector<vector<int>> &graph, vector<int> &color)
    {
        // mark the color :
        color[node] = colorValue;

        for (auto &neighbour : graph[node])
        {
            if (color[neighbour] == -1)
            {
                // recursive call with opposite color :
                // if any recursive call returns false : return false :
                if (!dfsCheck(neighbour, !colorValue, graph, color))
                    return false;
            }

            // if neighbour has same color as current node
            // then it's not bi-partite :
            else if (color[neighbour] != -1 && color[neighbour] == colorValue)
                return false;
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<int> color(n, -1); // visited array  : -1 means not visited

        // Multiple components :
        for (int i = 0; i < n; ++i)
        {
            if (color[i] == -1)
            {
                // if any component is not bi-partite :
                // then the graph is not bi-partite :
                if (!dfsCheck(i, 0, graph, color))
                    return false;
            }
        }

        return true;
    }
};

// gfg version :
class Solution
{
private:
    bool dfsCheck(int node, int colorValue, vector<vector<int>> &adj, vector<int> &color)
    {
        // mark the color :
        color[node] = colorValue;

        for (auto &neighbour : adj[node])
        {
            if (color[neighbour] == -1)
            {
                // recursive call with opposite color :
                // if any recursive call returns false : return false :
                if (!dfsCheck(neighbour, !colorValue, adj, color))
                    return false;
            }

            // if neighbour has same color as current node
            // then it's not bi-partite :
            else if (color[neighbour] != -1 && color[neighbour] == colorValue)
                return false;
        }

        return true;
    }

public:
    bool isBipartite(int V, vector<vector<int>> &edges)
    {
        // adjacency list is not given so create it :
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, -1); // visited array  : -1 means not visited

        for (int i = 0; i < V; ++i)
        {
            if (color[i] == -1)
            {
                // if any component is not bi-partite :
                // then the graph is not bi-partite :
                if (!dfsCheck(i, 0, adj, color))
                    return false;
            }
        }

        return true;
    }
};
