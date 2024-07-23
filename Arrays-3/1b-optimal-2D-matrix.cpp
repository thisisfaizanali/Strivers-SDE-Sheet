class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        // we notice that the matrix is sorted
        // agar sorted hai to -> binary search?
        // flattening matrix will take mn
        // we will instead find the 2d coordinates of elements
        // (row,column) = (index/no of col,index%no of col)
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = m * n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};