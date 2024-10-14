#include <bits/stdc++.h>
using namespace std;

// Function to partition the array into two halves around the pivot
// This function places the pivot element in its correct position
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];  // Choose the first element as the pivot
    int i = low, j = high; // Initialize two pointers, i (start) and j (end)

    // Loop until the two pointers cross
    while (i < j)
    {
        // Move 'i' to the right as long as elements are less than or equal to the pivot
        while (arr[i] <= pivot && i <= high - 1) // '=' is here because of duplicates of numbers
        {
            i++;
        }
        // Move 'j' to the left as long as elements are greater than the pivot
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        // If 'i' is still less than 'j', swap the elements at i and j
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    // After the loop, swap the pivot (arr[low]) with arr[j]
    // This places the pivot in its correct sorted position
    swap(arr[low], arr[j]);

    // Return the position of the pivot (partition index)
    return j;
}

// Recursive function to perform quicksort on the array
void quicksort(vector<int> &arr, int low, int high)
{
    // If the array has more than one element (base condition)
    if (low < high)
    {
        // Partition the array and get the index of the pivot element
        int partitionIndex = partition(arr, low, high);

        // Recursively quicksort the left part (elements smaller than the pivot)
        quicksort(arr, low, partitionIndex - 1);

        // Recursively quicksort the right part (elements greater than the pivot)
        quicksort(arr, partitionIndex + 1, high);
    }
}
int main()
{
    vector<int> arr = {3, 2, 4, 7, 1};
    int n = arr.size();
    cout << "Before quicksort" << endl;
    for (auto &x : arr)
        cout << x << " ";
    cout << endl;
    quicksort(arr, 0, n - 1);
    cout << "After quicksort" << endl;
    for (auto &x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}