/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // using bfs or kahn's algorithm :

        // we have to create adjacency list for DAG :
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
            adj[edge[0]].push_back(edge[1]);

        // calculate the indegree :
        vector<int> indegree(V, 0);

        for (int u = 0; u < V; ++u)
        {
            for (auto &v : adj[u])
            {
                indegree[v]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < V; ++i)
        {
            if (indegree[i] == 0)
            {
                // push nodes with indegree 0 to queue:
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            ans.push_back(node); // because the node already has indegree 0
            // and we push to queue only when the indegree is 0 :

            for (auto &neighbour : adj[node])
            {
                // remove the contribution of node on neighbour :
                // "node is done, so any adjacent node that needed node no longer needs it."
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                {
                    // push to queue when indegree is 0 :
                    q.push(neighbour);
                }
            }
        }

        return ans;
    }
};