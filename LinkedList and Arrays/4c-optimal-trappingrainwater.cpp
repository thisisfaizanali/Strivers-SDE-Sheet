/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        // Two-pointer technique to find the trapped water
        int left = 0;              // Pointer starting from the left
        int right = n - 1;         // Pointer starting from the right
        int left_max = 0;          // Max height encountered from the left
        int right_max = 0;         // Max height encountered from the right
        int totalTrappedWater = 0; // Accumulator for total trapped water

        // Iterate until the two pointers meet
        while (left < right)
        {
            // If the height at the left pointer is less than or equal to the right
            if (height[left] <= height[right])
            {
                // Update left_max if the current height is greater
                if (height[left] >= left_max)
                {
                    left_max = max(left_max, height[left]);
                }
                else
                {
                    // Water trapped at the current position
                    totalTrappedWater += left_max - height[left];
                }
                left++; // Move the left pointer to the right
            }
            else
            {
                // Update right_max if the current height is greater
                if (height[right] >= right_max)
                {
                    right_max = max(right_max, height[right]);
                }
                else
                {
                    // Water trapped at the current position
                    totalTrappedWater += right_max - height[right];
                }
                right--; // Move the right pointer to the left
            }
        }
        return totalTrappedWater;
    }
};

/*
Time Complexity: O(n)
- We traverse the array only once with the two-pointer technique.

Space Complexity: O(1)
- No extra space is used apart from a few variables for tracking.
*/
