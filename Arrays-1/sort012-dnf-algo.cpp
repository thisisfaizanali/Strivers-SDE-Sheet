class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // we will use three pointers mid low and high
        // this is also called as dutch national flag
        // O(n)
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        // [0,low-1]==0, [low,mid-1]==1 and [high,n-1]==2
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[high], nums[mid]);
                high--;
            }
        }
    }
};