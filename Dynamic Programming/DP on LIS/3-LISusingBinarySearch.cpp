/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;

// Cannot be used for generating actual LIS sequence :
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp; // temp[i] = smallest ending value for length (i+1)

        for (int &x : nums)
        {
            // Binary search: find position where x should go
            // lower_bound finds first element >= x
            int idx = lower_bound(temp.begin(), temp.end(), x) - temp.begin();

            if (idx == temp.size())
                // x is larger than all elements in temp
                // Extend the LIS by 1
                temp.push_back(x);
            else
            {
                // x fits in the middle
                // A subsequence of same length using this element can be made : so replace :
                // Replace temp[idx] with x (smaller ending is better)
                temp[idx] = x;
            }
        }

        // temp.size() = length of LIS
        return temp.size();
    }
};
