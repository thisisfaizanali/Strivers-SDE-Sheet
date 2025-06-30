/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// leetcode version :
class Solution
{
private:
    bool bfsCheck(int node, vector<vector<int>> &graph, vector<int> &color)
    {
        // queue for bfs :  queue : {node}
        queue<int> q;
        q.push(node);
        // mark the color :
        color[node] = 0; // start coloring from 0

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &neighbour : graph[node])
            {
                if (color[neighbour] == -1)
                {
                    color[neighbour] = !color[node]; // color should be opposite of node
                    q.push(neighbour);
                }
                // if neighbour has same color as node and it's visited
                // then it's not bi-partite :
                else if (color[node] != -1 && color[neighbour] == color[node])
                    return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();

        vector<int> color(n, -1); // visited array  : -1 means not visited

        // Mutliple components :
        for (int i = 0; i < n; ++i)
        {
            if (color[i] == -1)
            {
                // if any component is not bi-partite :
                // then the graph is not bi-partite :
                // using vice versa condition will lead to error :
                if (!bfsCheck(i, graph, color))
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
    bool bfsCheck(int node, vector<vector<int>> &adj, vector<int> &color)
    {
        // queue for bfs :  queue : {node}
        queue<int> q;
        q.push(node);
        // mark the color :
        color[node] = 0; // start coloring from 0

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &neighbours : adj[node])
            {
                if (color[neighbours] == -1)
                {
                    q.push(neighbours); // color should be opposite of node
                    color[neighbours] = !color[node];
                }

                // if neighbour has same color as node and it's visited
                // then it's not bi-partite :
                else if (color[neighbours] != -1 && color[neighbours] == color[node])
                    return false;
            }
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
                // using vice versa condition will lead to error :
                if (!bfsCheck(i, adj, color))
                    return false;
            }
        }

        return true;
    }
};