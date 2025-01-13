/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr; }();
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // maximum means -> monotonically decreasing stack (pge/nge type)
        int n = nums.size();
        vector<int> ans;
        // deque is used as stack as it offers both front and back operations
        deque<int> st; // we will play with indices
        for (int i = 0; i < n; ++i)
        {
            // Remove indices of only smaller values from the back of the deque
            while (!st.empty() && nums[st.back()] < nums[i])
                st.pop_back();
            st.push_back(i);
            // i is right boundary and i-k+1 is left boundary
            // i - (k - 1) is the start of the current window
            // Remove indices that are outside the current sliding window
            if (st.front() < i - (k - 1))
                st.pop_front();
            // max value index is always at front
            // Only do this after the first k elements (i >= k - 1)
            if (i >= k - 1)
                ans.push_back(nums[st.front()]);
        }
        return ans;
    }
};
