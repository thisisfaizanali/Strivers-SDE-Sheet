/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Shortest distane from one node to every other node  :
    // DP
    void floydWarshall(vector<vector<int>> &dist)
    {
        int n = dist.size();

        // Try every node k as an intermediate node
        for (int k = 0; k < n; ++k)
        {
            // For every source node i
            for (int i = 0; i < n; ++i)
            {
                // For every destination node j
                for (int j = 0; j < n; ++j)
                {
                    // Check if path i -> k and k -> j exists (to avoid overflow)
                    if (dist[i][k] < 1e8 && dist[k][j] < 1e8)
                    {
                        // Update shortest path i -> j via k if it's shorter
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
    }
};
