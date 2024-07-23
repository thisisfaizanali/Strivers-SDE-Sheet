class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // selected element is v[i]
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                // counting the frequency of v[i]
                if (v[j] == v[i])
                {
                    cnt++;
                }
            }

            // check if frquency is greater than n/2:
            if (cnt > (n / 2))
                return v[i];
        }
    }
};
