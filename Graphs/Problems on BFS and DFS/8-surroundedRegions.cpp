/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// leetcode version :
class Solution
{
private:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &board)
    {
        // dfs because i am thinking in terms of growing the region :

        int m = board.size();
        int n = board[0].size();

        vis[i][j] = 1;

        // neighbours can be in four directions :
        int nx[4] = {-1, 1, 0, 0};
        int ny[4] = {0, 0, 1, -1};

        for (int dir = 0; dir < 4; ++dir)
        {
            int ni = i + nx[dir];
            int nj = j + ny[dir];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                !vis[ni][nj] && board[ni][nj] == 'O')
                dfs(ni, nj, vis, board);
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // if the group or O is on boundary it's not possible :
        // boundary : first row,column and last row,column :

        for (int j = 0; j < n; ++j)
        {
            // first row ;
            if (board[0][j] == 'O' && !vis[0][j])
                dfs(0, j, vis, board);

            // last row :
            if (board[m - 1][j] == 'O' && !vis[m - 1][j])
                dfs(m - 1, j, vis, board);
        }

        for (int i = 0; i < m; ++i)
        {
            // first column :
            if (board[i][0] == 'O' && !vis[i][0])
                dfs(i, 0, vis, board);

            // last column :
            if (board[i][n - 1] == 'O' && !vis[i][n - 1])
                dfs(i, n - 1, vis, board);
        }

        // the unvisited cells are to be markes as all 'X' :

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

// gfg version :
class Solution
{
private:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        // dfs because i am thinking in terms of growing the region :
        vis[i][j] = 1;

        // neighbours can be in four directions :
        int nx[4] = {-1, 1, 0, 0};
        int ny[4] = {0, 0, 1, -1};

        for (int dir = 0; dir < 4; ++dir)
        {
            int ni = i + nx[dir];
            int nj = j + ny[dir];

            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                !vis[ni][nj] && mat[ni][nj] == 'O')
            {
                dfs(ni, nj, vis, mat);
            }
        }
    }

public:
    vector<vector<char>> fill(vector<vector<char>> &mat)
    {
        // main idea is that if the group is on the boundary
        // it cannot be converted
        // the boundary is first and last row and columns :

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // first and last rows :
        for (int j = 0; j < n; ++j)
        {
            // first row :
            if (mat[0][j] == 'O' && !vis[0][j])
            {
                dfs(0, j, vis, mat);
            }

            // last row :
            if (mat[m - 1][j] == 'O' && !vis[m - 1][j])
            {
                dfs(m - 1, j, vis, mat);
            }
        }

        // first and last column :
        for (int i = 0; i < m; ++i)
        {
            // first column :
            if (mat[i][0] == 'O' && !vis[i][0])
            {
                dfs(i, 0, vis, mat);
            }

            // first column :
            if (mat[i][n - 1] == 'O' && !vis[i][n - 1])
            {
                dfs(i, n - 1, vis, mat);
            }
        }

        // the unvisited cells should be marked as 'X' :
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!vis[i][j])
                {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};
