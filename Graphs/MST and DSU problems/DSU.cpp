/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Disjoint Set (Union-Find) Data Structure with Union by Rank and Union by Size
class DisjointSet
{
    // Vectors to store:
    // - rank: for union by rank optimization
    // - parent: to store the parent of each node
    // - size: for union by size optimization
    vector<int> rank, parent, size;

public:
    // Constructor: Initializes the DSU for 'n' elements (1-based indexing)
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0); // Initially, rank of all nodes is 0
        parent.resize(n + 1);  // Parent of each node will be initialized below
        size.resize(n + 1, 1); // Initially, each node is its own set of size 1

        // Each node is its own parent (self-rooted tree)
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    // Find the ultimate parent (root) of a node with path compression
    int findUltimateParent(int node)
    {
        // If node is its own parent, it's the root
        if (node == parent[node])
            return node;

        // Path compression: flatten the tree for faster future queries
        return parent[node] = findUltimateParent(parent[node]);
    }

    // Union two sets by rank (attach smaller depth tree under deeper one)
    void unionByRank(int u, int v)
    {
        int upu = findUltimateParent(u); // Ultimate parent of u
        int upv = findUltimateParent(v); // Ultimate parent of v

        // If they already belong to the same set, no need to union
        if (upu == upv)
            return;

        // Attach smaller rank tree under larger rank tree
        if (rank[upu] < rank[upv])
        {
            parent[upu] = upv;
        }
        else if (rank[upv] < rank[upu])
        {
            parent[upv] = upu;
        }
        else
        {
            // If ranks are equal, attach one to another and increment rank
            parent[upu] = upv;
            rank[upu]++;
        }
    }

    // Union two sets by size (attach smaller size tree under larger one)
    void unionBySize(int u, int v)
    {
        int upu = findUltimateParent(u); // Ultimate parent of u
        int upv = findUltimateParent(v); // Ultimate parent of v

        // If they already belong to the same set, no need to union
        if (upu == upv)
            return;

        // Attach smaller size tree under larger size tree and update size
        if (size[upu] < size[upv])
        {
            parent[upu] = upv;
            size[upv] += size[upu]; // Update the size of new parent set
        }
        else
        {
            parent[upv] = upu;
            size[upu] += size[upv]; // Update the size of new parent set
        }
    }
};
