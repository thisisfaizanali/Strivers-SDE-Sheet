/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        // safe nodes : those whose all paths lead to a terminal node :
        // So all nodes which are not a part of a cycle will get terminated :
        // i will use kahn topo method but first reverse the edges :
        // so nodes with outdegree now becomes nodes with indegree : so Kahn's algo can be used
        // this question : basically cycle detection approach for DG :
        int n = graph.size();

        vector<vector<int>> revGraph(n);
        vector<int> indegree(n, 0);

        for (int u = 0; u < n; ++u)
        {
            for (auto &v : graph[u])
            {
                revGraph[v].push_back(u); // reverse the edge directions
                indegree[u]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; ++i)
        {
            if (indegree[i] == 0) // these are terminal nodes
            {
                q.push(i);
            }
        }

        // Nodes in a cycle (or pointing to a cycle) will never reach indegree 0 in the reversed graph.
        vector<int> topo; // these will contain safe nodes

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            // Nodes in a cycle (or pointing to a cycle) will never reach indegree 0 in the reversed graph.
            topo.push_back(node);

            for (auto &neighbour : revGraph[node])
            {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        sort(topo.begin(), topo.end()); // ans should be in ascending order

        return topo;
    }
};