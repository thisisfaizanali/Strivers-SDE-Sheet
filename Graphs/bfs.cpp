/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        int V = adj.size(); // number of nodes or vertices
        // visited array of size V because of 0 based indexing :
        vector<int> vis(V, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;      // starting from node 0 so mark it as visited
        vector<int> bfs; // holds the answer
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.emplace_back(node);
            // Visit all unvisited neighbors of the current node :
            for (int neighbours : adj[node])
            {
                if (!vis[neighbours])
                {
                    vis[neighbours] = 1;
                    q.push(neighbours);
                }
            }
        }
        return bfs;
    }
};
