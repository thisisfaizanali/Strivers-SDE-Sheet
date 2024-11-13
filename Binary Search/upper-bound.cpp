#include <bits/stdc++.h>
using namespace std;
int ub(vector<int> &arr, int target, int n)
{
    int ans = n; // default answer
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target) // condition
        {
            ans = mid;      // probable answer
            high = mid - 1; // check for even smaller idx
        }
        else
            low = mid + 1;
    }
    return ans;
}
int main()
{
    vector<int> arr = {1, 3, 3, 5, 8, 8, 10};
    int target = 3;
    cout << ub(arr, target, arr.size());
    return 0;
}