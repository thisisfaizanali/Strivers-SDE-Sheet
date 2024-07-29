class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (nums[left] < nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; ++i)
        {
            nums[i] = temp[i - low];
        }
    }
    int mergesort(vector<int> &nums, int low, int high)
    {
        int count = 0;
        if (low >= high)
            return count;
        int mid = (low + high) / 2;
        count += mergesort(nums, low, mid);        // sorting left half
        count += mergesort(nums, mid + 1, high);   // sorting right half
        count += countpairs(nums, low, mid, high); // modification
        merge(nums, low, mid, high);               // merging
        return count;
    }
    int countpairs(vector<int> &nums, int low, int mid, int high)
    {
        int count = 0;
        int right = mid + 1;
        for (int i = low; i <= mid; ++i)
        {
            while (right <= high && (long long)nums[i] > (long long)2 * nums[right])
                right++;
            count += right - (mid + 1);
        }
        return count;
    }
    int reversePairs(vector<int> &nums)
    {
        // brute approach - tle
        // merge sort modification is used here
        // O(2n*log(n))
        // hard problem
        int n = nums.size();
        return mergesort(nums, 0, n - 1);
    }
};