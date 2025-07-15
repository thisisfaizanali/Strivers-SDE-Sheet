/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> rank, size, parent;
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

// from gfg :
class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {
        // Let:
        //     - n = total number of stones
        //     - c = number of connected components
        // Then:
        //     Maximum removable stones = n - c
        // Why?
        //     Because from each component, we must keep at least 1 stone.
        //     All other stones in that component can be removed.

        // 1 : Find max row and column :
        // Why? Because we'll create a graph where each row and column is a node.
        // Each cell as node and 4 directions fails :
        // because same r and col can be very far and most of cells will be empty :

        int maxRow = 0, maxCol = 0;
        for (auto &s : stones)
        {
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }

        // 2️ : Initialize DSU with enough space to represent all rows and columns
        // Total nodes needed = maxRow + maxCol + 2
        // Rows will occupy [0...maxRow]
        // Columns will occupy [maxRow+1 ... maxRow+1+maxCol]
        DSU ds(maxRow + maxCol + 2);

        // Set to store which row and column nodes were actually used
        set<int> used;

        // 3️ : Map each stone (i.e., each (row, col)) as an edge in the graph
        // Connect row node and column node in the DSU.
        for (auto &stone : stones)
        {
            int nodeRow = stone[0];              // row index directly used
            int nodeCol = stone[1] + maxRow + 1; // offset column index

            ds.unionByRank(nodeRow, nodeCol);

            used.insert(nodeRow);
            used.insert(nodeCol);
        }

        // 4️ : Count number of connected components using DSU
        // A component is represented by its ultimate parent in DSU.
        set<int> uniqueComponents;
        for (auto &u : used)
        {
            uniqueComponents.insert(ds.findUltimateParent(u));
        }

        return n - uniqueComponents.size();
    }
};
