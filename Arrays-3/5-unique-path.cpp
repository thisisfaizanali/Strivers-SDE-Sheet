class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // google interview question
        //  brute - using recursion
        // better - using dp
        // optimal - combinatorics
        // m-1 steps to go down and n-1 step to go right
        // total steps to choose from = m+n-2;
        // have to choose either m-1 or n-1
        int N = m + n - 2;
        // r is no of cols
        int r = m - 1;
        double res = 1;
        for (int i = 1; i <= r; ++i)
        {
            res = res * (N - r + i) / i;
        }
        return (int)res;
    }
};