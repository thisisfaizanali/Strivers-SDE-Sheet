/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

/*
LeetCode: 733. Flood Fill
Approach: DFS
- Start DFS from the given (sr, sc) pixel.
- Recurse to 4-directionally connected pixels that share the same initial color.
- Recolor them with the new color, using a separate matrix to preserve the original image during traversal.
Time Complexity: O(m × n)
    - Each cell is visited at most once in the worst case.
Space Complexity: O(m × n)
    - Due to recursion stack and the additional matrix used.
*/
class Solution
{
private:
    void dfs(int i, int j, vector<vector<int>> &image, vector<vector<int>> &mat, int newColor,
             int &initialColor)
    {
        int m = image.size();
        int n = image[0].size();

        // Recolor the current pixel
        mat[i][j] = newColor;

        // Four direction neighbours: up, down, right, left
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for (int dir = 0; dir < 4; ++dir)
        {
            int ni = i + dx[dir];
            int nj = j + dy[dir];

            // Check bounds, ensure not already recolored, and same as initial color
            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                mat[ni][nj] != newColor && image[ni][nj] == initialColor)
            {
                dfs(ni, nj, image, mat, newColor, initialColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        vector<vector<int>> mat = image;              // Copy original image to result matrix
        int initialColor = image[sr][sc];             // Store the color to be replaced
        dfs(sr, sc, image, mat, color, initialColor); // Begin DFS from the source pixel
        return mat;                                   // Return the updated image
    }
};
