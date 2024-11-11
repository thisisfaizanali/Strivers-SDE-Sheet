/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<string> findPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        vector<string> ans;                            // this will contain the answer
        vector<vector<int>> vis(n, vector<int>(n, 0)); // vis array
        // deviation arrays to easily calculate i and j for dir DLRU
        int di[] = {+1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if (mat[0][0] == 1)
        // this ques can be solved only if starting pos is 0,0 and has value 1
        {
            solve(0, 0, mat, vis, "", di, dj, ans, n); // recursive function
        }
        return ans; // return the ans
    }
    void solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &vis, string move, int di[], int dj[], vector<string> &ans, int n)
    {
        if (i == n - 1 && j == n - 1) // base case
        {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU"; // has directions to move
        for (int idx = 0; idx < 4; ++idx)
        {
            // new value of i and j upon movement
            int nexti = i + di[idx]; // they are the next coords
            int nextj = j + dj[idx]; // look at mark and unmark now
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && mat[nexti][nextj] == 1)
            {                  // boundary checks, !vis check and mat has value 1
                vis[i][j] = 1; // mark the current one
                solve(nexti, nextj, mat, vis, move + dir[idx], di, dj, ans, n);
                // call func
                vis[i][j] = 0; // unmark
            }
        }
    }
};
