/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // PIGEONHOLE PRINCIPLE:
        // Given an array of size (n+1) where numbers range from [1, n],
        // at least one number must repeat because there are more elements than unique values.
        // fast and slow pointers on arrays :
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        // meeting point of loop :
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        // meeting point is the answer :
        return slow;
    }
};