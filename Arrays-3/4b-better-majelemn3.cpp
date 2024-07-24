class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // at most there will be 2 elements which
        // occur more than n/3 times
        int n = nums.size();
        vector<int> ans;
        int mini = int(n / 3) + 1;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i)
        {
            freq[nums[i]]++;
            if (freq[nums[i]] == mini)
            {
                ans.emplace_back(nums[i]);
            }
            if (ans.size() == 2)
                break;
        }
        return ans;
    }
};