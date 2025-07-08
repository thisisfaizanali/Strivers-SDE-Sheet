/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Leetcode: Minimum Effort Path (from (0,0) to (m-1,n-1))
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();

        // Matrix to store the minimum effort required to reach each cell
        vector<vector<int>> effort(m, vector<int>(n, 1e9));
        effort[0][0] = 0;

        // Min-heap to always expand the path with the lowest current effort
        // Format: {effort_so_far, {row, col}}
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            minHeap;

        minHeap.push({0, {0, 0}}); // Start from top-left corner

        // 4-directional movement: up, down, right, left
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!minHeap.empty())
        {
            auto [currentEffort, cell] = minHeap.top();
            auto [row, col] = cell;
            minHeap.pop();

            // If we've reached the destination, return the effort
            if (row == m - 1 && col == n - 1)
                return currentEffort;

            for (int dir = 0; dir < 4; ++dir)
            {
                int ni = row + dx[dir];
                int nj = col + dy[dir];

                // Valid neighboring cell
                if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                {
                    // Effort to go from (row,col) → (ni,nj)
                    int effortToNext = abs(heights[row][col] - heights[ni][nj]);

                    // The new effort is the maximum effort along the path so far
                    int newEffort = max(currentEffort, effortToNext);

                    // Update only if we found a better (lower) effort path
                    if (newEffort < effort[ni][nj])
                    {
                        effort[ni][nj] = newEffort;
                        minHeap.push({newEffort, {ni, nj}});
                    }
                }
            }
        }

        // This point is unreachable in valid inputs (path always exists)
        return 0;
    }
};

class Solution
{
public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights)
    {
        int m = rows, n = columns;

        vector<vector<int>> effort(m, vector<int>(n, 1e9));
        effort[0][0] = 0;

        // Min-heap to get the path with the least current max effort
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            minHeap;

        minHeap.push({0, {0, 0}});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();

            int currentEffort = top.first;
            int row = top.second.first;
            int col = top.second.second;

            // Early return if destination is reached
            if (row == m - 1 && col == n - 1)
                return currentEffort;

            for (int dir = 0; dir < 4; ++dir)
            {
                int ni = row + dx[dir];
                int nj = col + dy[dir];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                {
                    int effortToNext = abs(heights[row][col] - heights[ni][nj]);
                    int newEffort = max(currentEffort, effortToNext);

                    if (newEffort < effort[ni][nj])
                    {
                        effort[ni][nj] = newEffort;
                        minHeap.push({newEffort, {ni, nj}});
                    }
                }
            }
        }

        // Unreachable for valid grids
        return 0;
    }
};
