/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // we want to do it using BFS :

        // Cool concept : if topological sorting can be done for all
        // n nodes : it's DAG so no cycle
        // but if it's done for < n nodes : cycle exists

        // So use Kahn's algorithm  :

        vector<vector<int>> adj(V);
        for (auto &edge : edges)
            adj[edge[0]].push_back(edge[1]);

        vector<int> indegree(V, 0);
        for (int u = 0; u < V; ++u)
        {
            for (auto &v : adj[u])
                indegree[v]++;
        }

        queue<int> q; // need q for bfs :

        for (int i = 0; i < V; ++i)
        {
            if (indegree[i] == 0)
                q.push(i); // push all nodes with indegree : 0
        }

        int count = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            count++;

            for (auto &neighbour : adj[node])
            {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        return count == V ? false : true;
    }
};