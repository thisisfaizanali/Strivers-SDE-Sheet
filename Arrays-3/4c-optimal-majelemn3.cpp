class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // at most there will be 2 unique elements which
        // occur more than n/3 times
        // cant simly use moore algo for two elements
        // cause of edge cases
        int count1 = 0, count2 = 0;
        int n = nums.size();
        int mini = int(n / 3) + 1;
        // this code will not work if el1 and 2 are not initialized to some sentinel value
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            // edge case check
            if (count1 == 0 && el2 != nums[i])
            {
                count1 = 1;
                el1 = nums[i];
            }
            // edge case check
            else if (count2 == 0 && el1 != nums[i])
            {
                count2 = 1;
                el2 = nums[i];
            }
            else if (nums[i] == el1)
            {
                count1++;
            }
            else if (nums[i] == el2)
            {
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == el1)
            {
                count1++;
            }
            if (nums[i] == el2)
            {
                count2++;
            }
        }
        if (count1 >= mini)
            ans.emplace_back(el1);
        if (count2 >= mini)
            ans.emplace_back(el2);
        return ans;
    }
};