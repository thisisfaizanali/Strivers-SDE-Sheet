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

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ans = 0;

        DSU ds(n * n);

        // Step 1 : first make all the connected components :
        for (int row = 0; row < n; ++row)
        {
            for (int col = 0; col < n; ++col)
            {
                if (grid[row][col] == 0)
                    continue;

                // components can be made in four directions :
                int dx[4] = {-1, 1, 0, 0};
                int dy[4] = {0, 0, 1, -1};

                for (int dir = 0; dir < 4; ++dir)
                {
                    int newRow = row + dx[dir];
                    int newCol = col + dy[dir];

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1)
                    {
                        int node = row * n + col;
                        int adjNode = newRow * n + newCol;

                        // Use unionBySize to get size later :
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }

        // Step 2 : Try changing each O to 1 and calculate size of components :
        for (int row = 0; row < n; ++row)
        {
            for (int col = 0; col < n; ++col)
            {
                if (grid[row][col] == 1)
                    continue;

                // Check for components in 4 directions :
                int dx[4] = {-1, 1, 0, 0};
                int dy[4] = {0, 0, 1, -1};

                // to store unique adjacent components : use set :
                set<int> components;

                for (int dir = 0; dir < 4; ++dir)
                {
                    int newRow = row + dx[dir];
                    int newCol = col + dy[dir];

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1)
                    {
                        int adjNode = newRow * n + newCol;

                        components.insert(ds.findUltimateParent(adjNode));
                    }
                }

                int newSize = 1; // count the 0 which was flipped to 1 :

                for (auto &comp : components)
                    newSize += ds.size[comp];

                ans = max(ans, newSize);
            }
        }

        // Step 3 : EDGE CASE : What if there was all 1 and no 0 :
        for (int i = 0; i < n * n; ++i)
        {
            ans = max(ans, ds.size[ds.findUltimateParent(i)]);
        }

        return ans;
    }
};