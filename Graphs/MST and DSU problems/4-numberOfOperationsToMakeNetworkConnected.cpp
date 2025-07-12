/*++++++++++++++++++++++++++++++++++++++++++++++++++++++ Bismillah +++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> rank, size, parent;

public:
    DSU(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int upu = findUltimateParent(u);
        int upv = findUltimateParent(v);
        if (upu == upv)
            return;

        if (rank[upu] < rank[upv])
            parent[upu] = upv;
        else if (rank[upu] > rank[upv])
            parent[upv] = upu;
        else
        {
            parent[upu] = upv;
            rank[upv]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int upu = findUltimateParent(u);
        int upv = findUltimateParent(v);
        if (upu == upv)
            return;

        if (size[upu] < size[upv])
        {
            parent[upu] = upv;
            size[upv] += size[upu];
        }
        else
        {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
    }
};

// GFG version :
class Solution
{
public:
    int minimumConnections(int n, vector<vector<int>> &connections)
    {
        // Connections is basically edges list :

        // From graph theory we know that :
        // If total edges are less than n-1, we can’t connect all components
        int e = connections.size();
        if (e < n - 1)
            return -1;

        DSU ds(n);

        // Make components using DSU :
        for (int i = 0; i < e; ++i)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            ds.unionByRank(u, v);
        }

        // Count how many connected components are there
        int numberOfConnectedComponents = 0;
        for (int i = 0; i < n; ++i)
        {
            if (ds.findUltimateParent(i) == i)
                numberOfConnectedComponents++;
        }

        // To connect all components, we need (components - 1) operations
        int ans = numberOfConnectedComponents - 1;
        return ans;
    }
};

// leetcode version :
class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        // Connections is basically edges list :

        // From Graph Theory :
        // To connect n nodes, we need at least n - 1 edges
        int e = connections.size();
        if (e < n - 1)
            return -1;

        DSU ds(n);

        // Make components using DSU
        for (int i = 0; i < e; ++i)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            ds.unionByRank(u, v);
        }

        // Count the number of connected components
        int numberOfConnectedComponents = 0;
        for (int i = 0; i < n; ++i)
        {
            if (ds.findUltimateParent(i) == i)
                numberOfConnectedComponents++;
        }

        // To connect n components, we need (n - 1) operations
        int ans = numberOfConnectedComponents - 1;
        return ans;
    }
};
