/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        // n X n matrix and we know the range
        int top = 0, down = n - 1;
        // top is candidate for answer and reducing the search space
        while (top < down)
        {
            if (mat[top][down] == 1) // top knows down
                top++;               // so top cannot be a celeb
            else                     // this means mat[top][down] == 0: top does not know down
                down--;              // so down cannot be a celeb
        }
        // feasibility check
        for (int i = 0; i < n; ++i)
        {
            if (i != top) // diagonal elements
            {
                if (mat[top][i] == 1 || mat[i][top] == 0)
                    return -1;
            }
        }
        return top;
    }
};
