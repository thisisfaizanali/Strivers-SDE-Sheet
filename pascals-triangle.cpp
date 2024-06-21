class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; ++i)
        {
            ans.push_back(myfunc(i));
        }
        return ans;
    }
    vector<int> myfunc(int row)
    {
        vector<int> tempo;
        tempo.push_back(1);
        long long res = 1;
        for (int col = 1; col < row; ++col)
        {
            res *= row - col;
            res /= col;
            tempo.push_back(res);
        }
        return tempo;
    }
};