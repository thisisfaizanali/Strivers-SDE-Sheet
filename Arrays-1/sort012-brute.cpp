class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // n objects which are red,white or blue
        // sort them in place
        //  0 1 2 == r w b
        // without sort function
        // since n is very small we can use bubble sort
        int n = nums.size();
        // this loop is for passes
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                // n-i-1 is for no of comparisons
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};