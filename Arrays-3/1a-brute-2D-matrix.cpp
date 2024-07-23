class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // m = rows and n=columns
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == target)
                {
                    ans = 1;
                    break;
                }
            }
        }
        if (ans == 1)
            return true;
        else
            return false;
    }
};