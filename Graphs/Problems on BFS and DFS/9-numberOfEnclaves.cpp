/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        // one move : walk from one land cell to another
        // adjacent land cell (4 directions) or walk off the boundary of grid :

        // the number of land cells for which we cannot walk off ??

        // Main Idea : if a land cell or a group of it is on the boundary
        // they can walk off
        // but the rest group of ones' cannot :

        // multi source bfs from boundary 1's and mark them as vis
        // the rest !vis cell with value = 1 are the answer :

        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0)); // vis grid
        // check the first row,col and last row,col for one and start bfs :

        queue<pair<int, int>> q; //{row,column}
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            int nx[4] = {-1, 1, 0, 0};
            int ny[4] = {0, 0, 1, -1};

            for (int dir = 0; dir < 4; ++dir)
            {
                int ni = row + nx[dir];
                int nj = col + ny[dir];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                    !vis[ni][nj] && grid[ni][nj] == 1)
                {
                    q.push({ni, nj});
                    vis[ni][nj] = 1;
                }
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};