/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        // Base case: only one matrix → no multiplication needed
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int minMult = 1e9; // Initialize to a large value

        // Try every possible partition point k between i and j-1
        for (int k = i; k < j; ++k)
        {
            // Recursively compute cost:
            // solve(i,k)    → cost to multiply left subchain (i..k)
            // solve(k+1,j)  → cost to multiply right subchain (k+1..j)
            // arr[i-1]*arr[k]*arr[j] → cost to multiply the two resulting matrices
            int operations = solve(i, k, arr, dp) + solve(k + 1, j, arr, dp) + (arr[i - 1] * arr[k] * arr[j]);
            minMult = min(minMult, operations);
        }

        return dp[i][j] = minMult;
    }

public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        // DP table: dp[i][j] stores min cost for matrices i..j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // Solve for the full chain of matrices from 1 to n-1
        return solve(1, n - 1, arr, dp);
    }
};
