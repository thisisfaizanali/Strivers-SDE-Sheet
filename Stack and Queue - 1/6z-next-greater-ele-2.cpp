/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        // nums is a circular integer array
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        // Traverse the array twice (2 * n - 1 to 0) to simulate the circular nature of the array.
        for (int i = 2 * n - 1; i >= 0; --i) // Start from the last element of the "doubled" array.
        {
            // Pop elements from the stack that are less than or equal to the current element.
            // These elements cannot be the "next greater" for the current element or any earlier elements.
            while (!st.empty() && st.top() <= nums[i % n])
                st.pop(); // Remove the top element of the stack.

            // If the stack is not empty, the top element is the "next greater element" for nums[i % n].
            if (!st.empty())
                nge[i % n] = st.top(); // Assign the next greater element for nums[i % n] in the result array.

            // Push the current element onto the stack as a potential "next greater element" for future elements.
            st.push(nums[i % n]);
        }
        return nge;
    }
};