/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Memoization :
class Solution
{
private:
    const int ninf = -1e9; // a large negative value used for invalid moves

private:
    int memoization(int i, int j1, int j2, vector<vector<int>> &grid, int m, int n,
                    vector<vector<vector<int>>> &memo)
    {
        // ---- boundary movement check ----
        // if either robot moves outside the grid, this path is invalid
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
            return ninf;

        // ---- base case: last row ----
        if (i == m - 1)
        {
            if (j1 == j2) // both robots on same cell → count once
                return grid[i][j1];
            else // different cells → count both
                return grid[i][j1] + grid[i][j2];
        }

        // ---- memoization check ----
        if (memo[i][j1][j2] != -1)
            return memo[i][j1][j2];

        int maxi = ninf;
        // ---- try all 9 possible moves (3 choices each robot) ----
        for (int dj1 = -1; dj1 <= 1; ++dj1)
        {
            for (int dj2 = -1; dj2 <= 1; ++dj2)
            {
                if (j1 == j2)
                    maxi = max(maxi, grid[i][j1] +
                                         memoization(i + 1, j1 + dj1, j2 + dj2, grid, m, n, memo));
                else
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] +
                                         memoization(i + 1, j1 + dj1, j2 + dj2, grid, m, n, memo));
            }
        }

        // ---- store result before returning ----
        return memo[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        // 3D memo table: dp[row][col1][col2]
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(n, -1)));

        // start at row 0, robot1 at col 0, robot2 at col n-1
        return memoization(0, 0, n - 1, grid, m, n, memo);
    }
};

// Tabulation :
class Solution
{
private:
    const int ninf = -1e9;

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 3D DP table: dp[row][col1][col2]
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, ninf)));

        // ---- base case: last row ----
        for (int j1 = 0; j1 < n; ++j1)
        {
            for (int j2 = 0; j2 < n; ++j2)
            {
                if (j1 == j2) // same cell
                    dp[m - 1][j1][j2] = grid[m - 1][j1];
                else // different cells
                    dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        // ---- fill dp from bottom row up to top ----
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j1 = 0; j1 < n; ++j1)
            {
                for (int j2 = 0; j2 < n; ++j2)
                {
                    int maxi = ninf;
                    // 9 possible moves
                    for (int dj1 = -1; dj1 <= 1; ++dj1)
                    {
                        for (int dj2 = -1; dj2 <= 1; ++dj2)
                        {
                            // ---- boundary check for next positions ----
                            if (j1 + dj1 >= 0 && j1 + dj1 < n &&
                                j2 + dj2 >= 0 && j2 + dj2 < n)
                            {
                                // same cell
                                if (j1 == j2)
                                    maxi = max(maxi, grid[i][j1] +
                                                         dp[i + 1][j1 + dj1][j2 + dj2]);
                                else // different cells
                                    maxi = max(maxi, grid[i][j1] + grid[i][j2] +
                                                         dp[i + 1][j1 + dj1][j2 + dj2]);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi; // store best for this state
                }
            }
        }

        // ---- answer is at top row, robot1=0, robot2=n-1 ----
        return dp[0][0][n - 1];
    }
};

// Space optimization :
class Solution
{
private:
    const int ninf = -1e9;

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // instead of dp[m][n][n], only keep 2 layers: prev and curr
        vector<vector<int>> prev(n, vector<int>(n, ninf)), curr(n, vector<int>(n, ninf));

        // ---- base case: last row ----
        for (int j1 = 0; j1 < n; ++j1)
        {
            for (int j2 = 0; j2 < n; ++j2)
            {
                if (j1 == j2)
                    prev[j1][j2] = grid[m - 1][j1];
                else
                    prev[j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
            }
        }

        // ---- bottom-up computation ----
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j1 = 0; j1 < n; ++j1)
            {
                for (int j2 = 0; j2 < n; ++j2)
                {
                    int maxi = ninf;
                    // 9 moves
                    for (int dj1 = -1; dj1 <= 1; ++dj1)
                    {
                        for (int dj2 = -1; dj2 <= 1; ++dj2)
                        {
                            int nj1 = j1 + dj1, nj2 = j2 + dj2;
                            // ---- boundary check ----
                            if (nj1 >= 0 && nj1 < n && nj2 >= 0 && nj2 < n)
                            {
                                // cherries at current row
                                int val = (j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2]);
                                // add best from next row
                                val += prev[nj1][nj2];
                                maxi = max(maxi, val);
                            }
                        }
                    }
                    curr[j1][j2] = maxi; // store for this row
                }
            }
            prev = curr; // roll arrays (make curr the new prev)
        }

        // ---- final answer at top row: robot1=0, robot2=n-1 ----
        return prev[0][n - 1];
    }
};
