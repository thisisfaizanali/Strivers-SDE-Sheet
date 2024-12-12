/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr; }();
class Solution
{
public:
    int findPages(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k > n)
            return -1;
        // numer of students > number of books available
        int low = *max_element(arr.begin(), arr.end());   // different students get the book
        int high = accumulate(arr.begin(), arr.end(), 0); // when one student gets all the books
        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);
            if (feasible(arr, mid, k))
                high = mid - 1; // min value chahiye
            else
                low = mid + 1;
        }
        return low;
    }
    bool feasible(vector<int> &arr, int mid, int k)
    {
        int currentPages = 0;
        int students = 1;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (currentPages + arr[i] <= mid)
                currentPages += arr[i];
            else
            {
                students++;            // more studs are required
                currentPages = arr[i]; // update the limit
                if (students > k)
                    return false;
            }
        }
        return true;
    }
};