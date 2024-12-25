/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<int> help_classmate(vector<int> arr, int n)
    {
        // this is akin to finding the next smaller element to the right
        vector<int> nse(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();
            if (!st.empty())
                nse[i] = st.top();
            st.push(arr[i]);
        }
        return nse;
    }
};