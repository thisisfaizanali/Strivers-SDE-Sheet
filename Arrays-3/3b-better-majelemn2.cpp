class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int ans;
        // tc - o(n)
        // sc - o(n)
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i)
        {
            // O(n)
            freq[nums[i]]++;
        }
        for (int i = 0; i < n; ++i)
        {
            // O(n)
            if (freq[nums[i]] > n / 2)
            {
                ans = nums[i];
            }
        }
        return ans;
    }
};