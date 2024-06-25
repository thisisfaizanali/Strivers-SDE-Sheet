#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0;
    long long maxi = LONG_MIN;
    int start_index = -1;
    int end_index = -1;
    int start = 0;
    for (int i = 0; i < n; ++i)
    {
        // obs1 starting index of subarray
        // will always start from where sum became 0
        if (sum == 0)
        {
            start = i;
        }
        sum += arr[i];
        // obs 2
        // ending index will be where max > last max
        if (sum > maxi)
        {
            maxi = sum;
            start_index = start;
            end_index = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    for (int i = start_index; i <= end_index; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return maxi;
}
int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}