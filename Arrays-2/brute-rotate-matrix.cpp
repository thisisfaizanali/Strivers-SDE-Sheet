class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // O(n2) space complexity also same;
        // make a 4x4 matrix and observe the pattern betwee i and j
        // i=j and j=n-1-i;
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(n));
        // this means ans will have n rows and each row is a vector of size n
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = ans;
    }
};