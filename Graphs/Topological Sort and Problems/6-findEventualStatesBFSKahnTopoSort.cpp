/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        // this question : basically cycle detection approach for DG :
        // for BFS version : we can use Kahn's algo for Topological Sorting :

        // Here terminal nodes have 0 outdegree but
        // Kahn is concerned with 0 indegree
        // so we have to reverse the edges (reverse the graph)

        // Terminal nodes are those with indegree 0 because of reversal of edges

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

        vector<int> topo; // these will contain safe nodes
                          // so we don't need extra safe node array :

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

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