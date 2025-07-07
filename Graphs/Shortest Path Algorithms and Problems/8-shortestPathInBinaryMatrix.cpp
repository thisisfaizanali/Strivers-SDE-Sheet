/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Returns shortest path length in a binary maze from source → destination
    // 1 = walkable, 0 = wall; if no path, returns -1
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        // No need of Dijsktra using minHeap or set of {distance,node}
        // Just use simple BFS because the cost or weight is 1 and it's a matrix :

        int m = grid.size();
        int n = grid[0].size();

        // If source or destination is blocked
        if (grid[source.first][source.second] != 1 || grid[destination.first][destination.second] != 1)
            return -1;

        // Distance matrix to track shortest path length from source
        vector<vector<int>> distance(m, vector<int>(n, 1e9));
        distance[source.first][source.second] = 0;

        // Standard BFS queue
        queue<pair<int, int>> q;
        q.push({source.first, source.second});

        // 4-directional movement: up, down, right, left
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; ++dir)
            {
                int ni = row + dx[dir];
                int nj = col + dy[dir];

                // Within bounds, walkable, and offers shorter distance
                if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                    grid[ni][nj] == 1 && distance[row][col] + 1 < distance[ni][nj])
                {
                    distance[ni][nj] = distance[row][col] + 1;
                    q.push({ni, nj});
                }
            }
        }

        int destDist = distance[destination.first][destination.second];
        return destDist == 1e9 ? -1 : destDist;
    }
};

// Leetcode variation: shortest path in binary matrix (0 = walkable, 1 = blocked)
// 8-directional movement, top-left → bottom-right
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        // If starting or ending cell is blocked
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        // Distance matrix to track number of steps (cells visited)
        vector<vector<int>> distance(n, vector<int>(n, 1e9));
        distance[0][0] = 1; // Here you have to count the number of visited cells (0) and not steps

        queue<pair<int, int>> q;
        q.push({0, 0});

        // 8-directional movement (including diagonals)
        int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            for (int dir = 0; dir < 8; ++dir)
            {
                int ni = row + dx[dir];
                int nj = col + dy[dir];

                if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                    grid[ni][nj] == 0 && distance[row][col] + 1 < distance[ni][nj])
                {
                    distance[ni][nj] = distance[row][col] + 1;
                    q.push({ni, nj});
                }
            }
        }

        int endDist = distance[n - 1][n - 1];
        return endDist == 1e9 ? -1 : endDist;
    }
};