/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid,
             vector<pair<int, int>> &shapes, int baseRow, int baseColumn)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Mark the current cell as visited
        vis[i][j] = 1;

        // Record the relative position of the current cell to the base of the island
        // we are normalizing here :
        shapes.push_back({i - baseRow, j - baseColumn});

        int nx[4] = {-1, 1, 0, 0};
        int ny[4] = {0, 0, 1, -1};

        // Explore all 4 directions
        for (int dir = 0; dir < 4; ++dir)
        {
            int ni = i + nx[dir];
            int nj = j + ny[dir];

            // Check bounds and if the neighbor is unvisited land
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[ni][nj] &&
                grid[ni][nj] == 1)
            {
                dfs(ni, nj, vis, grid, shapes, baseRow, baseColumn);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // two islands are distinct  if their shapes (relative structure) differ.
        // we will use normalization to identify identical ones
        // and push them to a set :

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        set<vector<pair<int, int>>> st; // set to store unique island shapes

        // Traverse the entire grid
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // If cell is unvisited land, start DFS
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> shapes;      // holds the shape of the current island
                    dfs(i, j, vis, grid, shapes, i, j); // explore the island
                    st.insert(shapes);                  // insert the shape into the set (auto handles duplicates)
                }
            }
        }

        // Number of distinct shapes found
        return st.size();
    }
};
