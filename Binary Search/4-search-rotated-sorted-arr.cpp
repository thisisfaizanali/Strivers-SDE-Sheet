/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        // a rotated sorted array will always have atleast 1 sorted half
        // either from low to mid or mid to high or both
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[low] <= nums[mid]) // if left half is sorted
            {
                if (nums[low] <= target && nums[mid] >= target)
                {
                    high = mid - 1; // if present eliminate the right half
                }
                else
                {
                    low = mid + 1; // if not present eliminate left half
                }
            }
            else // if right half is sorted
            {
                if (nums[mid] <= target && nums[high] >= target)
                {
                    low = mid + 1; // if present eliminate left half
                }
                else
                {
                    high = mid - 1; // if not present eliminate right half
                }
            }
        }
        return -1;
    }
};