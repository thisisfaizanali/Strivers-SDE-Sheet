/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<int> findpse(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        // we want index to play with
        // that is why using index for stacks
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && arr[st.top()] > arr[i]) // = equal sign is not here to properly count all
                st.pop();
            // edge case -> if no pse : -1
            pse[i] = st.empty() ? -1 : st.top(); // give idx
            st.push(i);
        }
        return pse;
    }
    vector<int> findnse(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && arr[st.top()] >= arr[i]) // = equal sign will be here
                st.pop();
            // edge case -> if no nse : n
            nse[i] = st.empty() ? n : st.top(); // give idx
            st.push(i);
        }
        return nse;
    }
    int sumSubarrayMins(vector<int> &arr)
    {
        // this approach will revolve around contribution of elements
        //  arr[i] * number of subarrays in which they are min element
        // we will use nse and pse for this purpose
        int n = arr.size();
        vector<int> pse = findpse(arr);
        vector<int> nse = findnse(arr);
        long long mod = 1e9 + 7;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            long long leftCount = i - pse[i];
            long long rightCount = nse[i] - i;
            sum += (arr[i] * leftCount * rightCount) % mod;
        }
        return sum % mod;
    }
};