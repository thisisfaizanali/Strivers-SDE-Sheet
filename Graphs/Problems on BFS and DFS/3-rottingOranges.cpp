/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

/*
LeetCode: 994. Rotting Oranges
Approach: Multi-source BFS from initially rotten oranges
- At each minute, rotten oranges rot their 4-directionally adjacent fresh oranges.
- Use a queue to simulate the time-based spread.
- Track visited cells to avoid revisiting and count how many fresh oranges get rotted.

Time Complexity: O(m × n)  — Each cell is visited at most once
Space Complexity: O(m × n) — Visited matrix + queue in worst case
*/
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 0: empty cell, 1: fresh orange, 2: rotten orange
        vector<vector<int>> vis(m, vector<int>(n, 0)); // visited grid
        int freshOranges = 0;

        // Multi-source BFS: enqueue all initially rotten oranges with time = 0
        // q : ({{r,c},time}):
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // start from rotten oranges :
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1; // Mark rotten orange as visited
                }
                else if (grid[i][j] == 1)
                {
                    freshOranges++; // Count total fresh oranges
                }
            }
        }

        int time = 0;           // Total minutes elapsed
        int orangesDamaged = 0; // Count of fresh oranges turned rotten

        // Directions: up, right, down, left
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int row = it.first.first;
            int col = it.first.second;
            int t = it.second;

            time = max(time, t); // Track the max time taken

            // Check 4-directionally adjacent cells
            for (int dir = 0; dir < 4; ++dir)
            {
                int ni = row + dx[dir];
                int nj = col + dy[dir];

                // Valid fresh neighbor and unvisited
                if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                    !vis[ni][nj] && grid[ni][nj] == 1)
                {
                    vis[ni][nj] = 1;
                    q.push({{ni, nj}, t + 1}); // Rot at time + 1
                    orangesDamaged++;
                }
            }
        }

        // If all fresh oranges were rotted, return total time
        if (orangesDamaged == freshOranges)
            return time;

        // If some fresh oranges couldn't be rotted
        return -1;
    }
};
