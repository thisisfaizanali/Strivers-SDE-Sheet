/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

/*
 * Time Complexity: O(M*N) where M is number of rows and N is number of columns
 * Space Complexity: O(M*N) for the queue and visited matrix in worst case
 *
 * Approach:
 * 1. The solution uses multi-source BFS which is optimal for this grid problem
 * 2. All source nodes (0s or 1s depending on problem) are added to the queue first
 * 3. We then process each node's neighbors, marking them as visited and
 *    incrementing the distance by 1 for each level
 * 4. This ensures the first time we visit a node is via the shortest path
 */

// LeetCode version: Distance of nearest 0 for each cell
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        // Initialize answer matrix and visited matrix
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // Queue stores ((row, col), current_distance)
        queue<pair<pair<int, int>, int>> q;

        // Multi-source BFS initialization:
        // Add all 0 cells as sources with initial distance 0
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0)
                {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        // BFS traversal
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            ans[row][col] = distance;

            // Explore all 4-directional neighbors
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, 1, -1};

            for (int dir = 0; dir < 4; ++dir)
            {
                int ni = row + dx[dir];
                int nj = col + dy[dir];

                // Check if neighbor is within bounds and not visited
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !vis[ni][nj])
                {
                    vis[ni][nj] = 1;
                    q.push({{ni, nj}, distance + 1});
                }
            }
        }

        return ans;
    }
};

// GFG version: Distance of nearest 1 for each cell
class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Initialize answer matrix and visited matrix
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Queue stores ((row, col), current_distance)
        queue<pair<pair<int, int>, int>> q;

        // Multi-source BFS initialization:
        // Add all 1 cells as sources with initial distance 0
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

        // BFS traversal
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;
            q.pop();

            ans[row][col] = distance;

            // Explore all 4-directional neighbors
            int dx[4] = {-1, 1, 0, 0};
            int dy[4] = {0, 0, 1, -1};

            for (int dir = 0; dir < 4; ++dir)
            {
                int ni = row + dx[dir];
                int nj = col + dy[dir];

                // Check if neighbor is within bounds and not visited
                if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj])
                {
                    vis[ni][nj] = 1;
                    q.push({{ni, nj}, distance + 1});
                }
            }
        }

        return ans;
    }
};