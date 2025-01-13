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
        // i is candidate for being a celeb
        for (int i = 0; i < n; ++i)
        {
            bool celeb = true;
            for (int j = 0; j < n; ++j)
            {
                if (i != j) // diagonal elements
                {
                    if (mat[i][j] == 1 || mat[j][i] == 0) // conditions are violated
                    {
                        celeb = false;
                        break;
                    }
                }
            }
            if (celeb)
                return i;
        }
        return -1;
    }
};
