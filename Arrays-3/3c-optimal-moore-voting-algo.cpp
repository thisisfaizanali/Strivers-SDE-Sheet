class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // moore voting algo
        //++ -- socho
        int n = nums.size();
        int el;
        int count = 0;
        // find possible candidate for maj elem
        for (int i = 0; i < n; ++i)
        {
            if (count == 0)
            {
                count = 1;
                el = nums[i];
            }
            else if (nums[i] == el)
                count++;
            else
                count--;
        }
        // check if that elem is really the maj elem
        int count2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == el)
            {
                count2++;
            }
        }
        if (count2 > (n / 2))
            return el;
        else
            return -1;
    }
};