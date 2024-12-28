/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> st;
        int area = 0;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
            {
                int el = st.top();                    // Index of the bar being processed
                st.pop();                             // Remove the processed bar
                int nse = i;                          // Next Smaller Element is the current index
                int pse = st.empty() ? -1 : st.top(); // Previous Smaller Element index (-1 if stack is empty)
                // Calculate the width and the area:
                // Width = nse - pse - 1
                area = max(area, (heights[el] * (nse - pse - 1)));
            }
            // Push the current index onto the stack
            st.push(i);
        }

        // Process remaining elements in the stack (for bars that do not have a smaller bar to the right)
        while (!st.empty())
        {
            int el = st.top();                    // Index of the bar being processed
            st.pop();                             // Remove the processed bar
            int nse = n;                          // If no NSE, assume the right boundary is the end of the array
            int pse = st.empty() ? -1 : st.top(); // Previous Smaller Element index (-1 if stack is empty)
            // Calculate the width and the area:
            // Width = nse - pse - 1
            area = max(area, (heights[el] * (nse - pse - 1)));
        }

        // Return the maximum area found
        return area;
    }
};