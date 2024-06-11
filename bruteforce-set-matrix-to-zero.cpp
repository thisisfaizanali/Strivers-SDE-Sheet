class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // m is to find the row of the matrix
        // n for columns
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstrowhaszero = false;
        bool firstcolhaszero = false;

        // checking if first row has zeros
        for (int j = 0; j < n; ++j)
        {
            if (matrix[0][j] == 0)
            {
                firstrowhaszero = true;
                break;
            }
        }
        // same for first column
        for (int i = 0; i < m; ++i)
        {
            if (matrix[i][0] == 0)
            {
                firstcolhaszero = true;
                break;
            }
        }
        // Using the first row and column to mark zero rows and columns
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // using markers to mark row and cols as zero
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (firstrowhaszero)
        {
            for (int j = 0; j < n; ++j)
            {
                matrix[0][j] = 0;
            }
        }

        if (firstcolhaszero)
        {
            for (int i = 0; i < m; ++i)
            {
                matrix[i][0] = 0;
            }
        }
    }
};