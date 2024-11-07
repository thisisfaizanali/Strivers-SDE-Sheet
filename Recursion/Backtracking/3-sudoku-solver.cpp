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
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board); // calling of recursive solution
    }

private:
    bool solve(vector<vector<char>> &board)
    {
        // loop over each 9 X 9 cell in the grid
        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                // if cell is empty
                if (board[row][col] == '.')
                {
                    // let us try placing each number
                    for (char num = '1'; num <= '9'; ++num)
                    {
                        // check if that number can be placed
                        if (isValid(board, row, col, num) == true)
                        {
                            board[row][col] = num;
                            // we are using true and false to recursively solve for all
                            if (solve(board) == true)
                            {
                                return true;
                            }
                            // back track
                            board[row][col] = '.';
                        }
                    }
                    return false; // if could not be filled
                }
            }
        }
        // if we reach here everything is filled perfectly
        return true;
    }

private:
    // function to check validity
    bool isValid(vector<vector<char>> &board, int row, int col, char num)
    {
        for (int i = 0; i < 9; ++i)
        {
            // check if number is already present in row
            if (board[row][i] == num)
            {
                return false;
            }
            // check if number is already present in col
            if (board[i][col] == num)
            {
                return false;
            }
            // check if number is already present in 3 X 3 grid
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
            {
                // remember this formula
                // related to find row col of a 2d matrix using i variable
                return false;
            }
        }
        return true;
    }
};