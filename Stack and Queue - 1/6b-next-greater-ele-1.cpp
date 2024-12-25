/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums2.size();
        vector<int> nge(n, -1); // Initialize with -1 (no greater element by default)
        stack<int> s;           // Stack to store elements for backward traversal

        // Traverse nums2 backwards (from end to start)
        for (int i = n - 1; i >= 0; --i)
        {
            // Pop elements from the stack that are less than or equal to the current element
            while (!s.empty() && s.top() <= nums2[i])
            {
                s.pop();
            }

            // If the stack is not empty, the top of the stack is the next greater element
            if (!s.empty())
            {
                nge[i] = s.top(); // Store the next greater element for nums2[i]
            }

            // Push the current element onto the stack for future comparisons
            s.push(nums2[i]);
        }

        // Prepare the result for nums1
        vector<int> result;
        for (int num : nums1)
        {
            // Get the next greater element for each number in nums1
            result.push_back(nge[find(nums2.begin(), nums2.end(), num) - nums2.begin()]);
        }

        return result;
    }
};
