#include <bits/stdc++.h>
using namespace std;
void mergearr(vector<int> &arr, int low, int mid, int high)
{
    // here merging occurs after the comparison and sorting part
    vector<int> temp;                // temp list to hold arr elements
    int left = low, right = mid + 1; // two pointer approach to compare elements of the two parts
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]); // temp list to hold
        else
            temp.push_back(arr[right++]); // temp list to hold
    }
    while (left <= mid)
    {
        // if anything left on the 1st part
        temp.push_back(arr[left++]);
    }
    while (right <= high)
    {
        // if anything left on the 2nd part
        temp.push_back(arr[right++]);
    }
    for (size_t i = low; i <= high; ++i)
        arr[i] = temp[i - low]; // array elements are placed
}
void mergesort(vector<int> &arr, int low, int high)
{
    // Here the dividing part of the array occurs
    if (low >= high) // base case
        return;      // basically stop when there is only one element left
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);      // first part of arr
    mergesort(arr, mid + 1, high); // second part of arr
    mergearr(arr, low, mid, high); // the merging occurs after comparing
}
int main()
{
    vector<int> arr = {4, 2, 1, 3, 5};
    int n = arr.size();
    cout << "Before Merge Sort" << endl;
    for (auto &x : arr)
        cout << x << " ";
    cout << endl;
    mergesort(arr, 0, n - 1);
    cout << "After Merge Sort" << endl;
    for (auto x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}