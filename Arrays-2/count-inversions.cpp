/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        // from void -> int
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        int count = 0; // declare
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                count += mid - left + 1; // this is the main line or answer
                temp.push_back(arr[right++]);
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left++]);
        }
        while (right <= high)
        {
            temp.push_back(arr[right++]);
        }
        for (int i = low; i <= high; ++i)
        {
            arr[i] = temp[i - low];
        }
        return count; // return
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        // from void-> int
        int count = 0; // count
        if (low >= high)
        {
            return count;
        }
        int mid = (low + high) / 2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
        return count;
    }
    int inversionCount(vector<int> &arr)
    {
        // we are going to use merge sort patter
        // very similar to reverse pairs
        int n = arr.size();
        return mergeSort(arr, 0, n - 1);
    }
};
