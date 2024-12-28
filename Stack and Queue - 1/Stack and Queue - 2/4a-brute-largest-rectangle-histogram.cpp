/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<int> findnse(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findpse(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if (!st.empty())
                pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    int largestRectangleArea(vector<int> &heights)
    {
        // we have to play boundaries so indexes not maxleft or maxright
        // brute force using nse and pse
        int n = heights.size();
        vector<int> nse = findnse(heights);
        vector<int> pse = findpse(heights);
        int area = 0;
        for (int i = 0; i < n; ++i)
        {
            area = max(area, (heights[i] * (nse[i] - pse[i] - 1)));
        }
        return area;
    }
};