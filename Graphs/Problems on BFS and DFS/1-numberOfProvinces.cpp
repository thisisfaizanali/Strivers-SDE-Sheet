/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

/*
LeetCode: 547. Number of Provinces
Approach: DFS on adjacency matrix
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
class Solution
{
private:
    void dfs(int node, vector<vector<int>> &isConnected, vector<int> &vis)
    {
        vis[node] = 1;
        for (int j = 0; j < isConnected.size(); ++j)
        {
            // look for the unvisited neighbours of the node :
            if (isConnected[node][j] == 1 && !vis[j])
                dfs(j, isConnected, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        // count the total number of components of undirected graph :
        int n = isConnected.size(); // n is the number of cities
        vector<int> vis(n, 0);      // visited array to track cities
        int numProvinces = 0;       // number of components
        for (int i = 0; i < n; ++i)
        {
            // ans will be how many times dfs or bfs is triggered for each unvisited city :
            if (!vis[i])
            {
                numProvinces++; // new component found so increment
                dfs(i, isConnected, vis);
            }
        }
        return numProvinces;
    }
};