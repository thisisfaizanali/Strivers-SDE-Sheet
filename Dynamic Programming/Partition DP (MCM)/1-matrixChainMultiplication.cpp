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

// Tabulation:
class Solution
{
public:
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size(); // total number of dimensions (matrices = n - 1)

        // dp[i][j] will store the minimum cost to multiply matrices from i to j
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));

        // Base case: cost of multiplying one matrix = 0
        for (int i = 1; i < n; ++i)
            dp[i][i] = 0;

        // i goes backward so that dp[k+1][j] (right subproblem) is already computed
        for (int i = n - 1; i >= 1; --i)
        {
            // j always starts after i:
            for (int j = i + 1; j < n; ++j)
            {
                // try all possible partitions between i and j
                for (int k = i; k < j; ++k)
                {
                    int operations = (arr[i - 1] * arr[k] * arr[j]) + dp[i][k] + dp[k + 1][j];
                    dp[i][j] = min(dp[i][j], operations);
                }
            }
        }

        // final answer: minimum cost to multiply entire chain (1..n-1)
        return dp[1][n - 1];
    }
};
