class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        // brute solution - 4 loops
        // better - 3 loops, using hashset
        // will use two pointer like technique
        // nums[i],j,k,l = target
        // will fix i and j
        // use O(n3) time
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // ans can be returned in any order
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            // checking for duplicate
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; ++j)
            {
                // checking for duplicate
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.emplace_back(temp);
                        k++;
                        l--;
                        // checking for duplicates like i and j
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        // checking for duplicates like i and j
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};