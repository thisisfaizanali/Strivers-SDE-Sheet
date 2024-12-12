/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0]; // if there is single element only
        if (nums[0] != nums[1])
            return nums[0]; // standing at beginning and its the answer
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        // standing at end and its the answer
        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // base case
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            {
                return nums[mid];
            }
            else if ((mid % 2 != 0 && nums[mid - 1] == nums[mid]) || // Odd index, left pair matches
                     (mid % 2 == 0 && nums[mid] == nums[mid + 1]))   // Even index, right pair matches
            // we are in left half
            {
                // ans cannot be in left half
                //  eliminate it and move to right half
                low = mid + 1;
            }
            else
            {
                // we are in right half
                // move to left half
                high = mid - 1;
            }
        }
        return -1;
    }
};