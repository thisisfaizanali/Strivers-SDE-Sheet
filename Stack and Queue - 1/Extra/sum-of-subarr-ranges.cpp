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

    vector<int> findpge(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pge(n, -1);
        stack<int> st;
        // we want index to play with
        // that is why using index for stacks
        for (int i = 0; i < n; ++i)
        {
            while (!st.empty() && arr[st.top()] < arr[i]) // No "=" sign to avoid counting equal elements
                st.pop();
            // edge case -> if no pge : -1
            pge[i] = st.empty() ? -1 : st.top(); // give idx
            st.push(i);
        }
        return pge;
    }

    vector<int> findnge(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i)
        {
            while (!st.empty() && arr[st.top()] <= arr[i]) // "=" sign is here to handle equality
                st.pop();
            // edge case -> if no nge : n
            nge[i] = st.empty() ? n : st.top(); // give idx
            st.push(i);
        }
        return nge;
    }

    long long sumSubarrayMins(vector<int> &arr)
    {
        // this approach will revolve around contribution of elements
        //  arr[i] * number of subarrays in which they are min element
        // we will use nse and pse for this purpose
        int n = arr.size();
        vector<int> pse = findpse(arr);
        vector<int> nse = findnse(arr);
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            long long leftCount = i - pse[i];
            long long rightCount = nse[i] - i;
            sum += (arr[i] * leftCount * rightCount);
        }
        return sum;
    }

    long long sumSubarrayMaxs(vector<int> &arr)
    {
        // this approach will revolve around contribution of elements
        // arr[i] * number of subarrays in which they are max element
        // we will use nge and pge for this purpose
        int n = arr.size();
        vector<int> pge = findpge(arr);
        vector<int> nge = findnge(arr);
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            long long leftCount = i - pge[i];
            long long rightCount = nge[i] - i;
            sum += (arr[i] * leftCount * rightCount);
        }
        return sum;
    }

    long long subArrayRanges(vector<int> &nums)
    {
        size_t n = nums.size();
        long long sum = 0;
        sum += sumSubarrayMaxs(nums); // Contribution of max elements
        sum -= sumSubarrayMins(nums); // Contribution of min elements
        return sum;
    }
};
