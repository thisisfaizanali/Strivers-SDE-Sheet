class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // O(n) time
        //  x + y = target
        int n = nums.size();
        unordered_map<int, int> mp;
        // keep track of array values and indices
        for (int i = 0; i < n; ++i)
        {
            int currentnums = nums[i];
            int complement = target - currentnums;
            // check if it exists in the map
            if (mp.count(complement))
                return {mp[complement], i};
            mp[currentnums] = i;
        }
        return {};
    }
};