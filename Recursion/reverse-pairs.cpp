/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        int count = 0;
        vector<int> temp;
        int left = low, right = mid + 1;
        int j = mid + 1;
        for (int i = low; i <= mid; ++i)
        {
            while (j <= high && arr[i] > 2 * 1ll * arr[j])
            {
                j++;
            }
            count += j - (mid + 1);
        }
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
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
            arr[i] = temp[i - low];
        return count;
    }
    int mergeSort(vector<int> &arr, int low, int high)
    {
        int count = 0;
        if (low >= high)
        {
            return count;
        }
        int mid = low + ((high - low) >> 1);
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
        return count;
    }
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};