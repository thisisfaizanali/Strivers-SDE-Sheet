/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
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

class Solution
{
public:
    // Example of Online Queries :
    // Connection + Dynamic Graph -> DSU
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // the cells of the grid are the nodes :
        DSU ds(n * m);

        // grid array to track land or sea :
        vector<vector<int>> grid(n, vector<int>(m, 0)); // initially all sea or 0

        // to count the number of islands or components :
        int count = 0;
        // to store the answer :
        vector<int> ans;

        for (auto &o : operators)
        {
            int row = o[0];
            int col = o[1];

            if (grid[row][col] == 1)
            {
                // if already land : store count and skip to next iterations :
                ans.push_back(count);
                continue;
            }

            grid[row][col] = 1; // else make it land
            count++;            // new island or component : so increment it

            // 4 directions :
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, 1, -1};

            // Process neighbours :
            for (int dir = 0; dir < 4; ++dir)
            {
                int adjR = row + dx[dir];
                int adjC = col + dy[dir];

                // Check for bounds and land node :
                if (adjR >= 0 && adjR < n && adjC >= 0 && adjC < m &&
                    grid[adjR][adjC] == 1)
                {
                    // find out the node and adjNode using the formula :
                    // node = curentRow * Given Column length + currentColumn :

                    int node = row * m + col;
                    int adjNode = adjR * m + adjC;

                    // Check whether they are part of different node or component:
                    // If yes decremrent : count
                    if (ds.findUltimateParent(node) != ds.findUltimateParent(adjNode))
                    {
                        count--;
                        ds.unionByRank(node, adjNode); // connect them
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};