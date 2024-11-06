/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define eb emplace_back
#define all(p) p.begin(), p.end()
#define idx size_t
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        // the size of the board is n X n
        vector<vector<string>> ans;              // holds the answer
        vector<string> board(n, string(n, '.')); // this is the board initialized with '.'
        // we will use hashing to solve this problem
        vector<int> leftrow(n, 0), leftdiagonal(2 * n - 1, 0), rightdiagonal(2 * n - 1, 0);
        solve(0, board, ans, leftrow, leftdiagonal, rightdiagonal, n); // recursive function
        return ans;
    }

private:
    void solve(int cols, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftrow, vector<int> &leftdiagonal, vector<int> &rightdiagonal, int n)
    {
        if (cols == n) // base case
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; ++row)
        {
            if (leftrow[row] == 0 && leftdiagonal[cols + row] == 0 && rightdiagonal[n - 1 + cols - row] == 0)
            {
                // check if empty or not occupied:
                board[row][cols] = 'Q';
                leftrow[row] = 1;
                leftdiagonal[cols + row] = 1;
                rightdiagonal[n - 1 + cols - row] = 1;
                solve(cols + 1, board, ans, leftrow, leftdiagonal, rightdiagonal, n);
                // back tracking steps
                board[row][cols] = '.';
                leftrow[row] = 0;
                leftdiagonal[cols + row] = 0;
                rightdiagonal[n - 1 + cols - row] = 0;
            }
        }
    }
};