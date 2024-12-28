/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        // histogram based solution
        // row wise -> largestRect
        int area = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        // Vector to store the heights of the histogram for each column.
        vector<int> heights(n, 0);

        // Iterate over each row in the matrix.
        for (int i = 0; i < m; ++i)
        {
            // Iterate over each column in the current row.
            for (int j = 0; j < n; ++j)
            {
                // If the cell value is '1', increase the corresponding column height.
                if (matrix[i][j] == '1') // as mat is char type
                {
                    heights[j] += 1;
                }
                // If the cell value is '0', reset the height for that column.
                else
                {
                    heights[j] = 0;
                }
            }
            // After updating the heights, calculate the largest rectangle area using histogram heights.
            area = max(area, largestRect(heights));
        }
        return area;
    }
    int largestRect(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        int area = 0;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                area = max(area, (arr[el] * (nse - pse - 1)));
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int el = st.top();
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            area = max(area, (arr[el] * (nse - pse - 1)));
        }
        return area;
    }
};