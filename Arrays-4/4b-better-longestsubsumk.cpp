class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        // use hashing
        // store sum and index
        long long k = 0; // if given sum is 0;
        int maxlen = 0;
        map<long long, int> prefixsum;
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += arr[i];
            if (sum == k)
            {
                maxlen = max(len, i + 1);
            }
            long long rem = sum - k;
            if (prefixsum.find(rem) != prefixsum.end())
            {
                int len = i - prefixsum[sum];
                maxlen = max(maxlen, len);
            }
            if (prefixsum.find(sum) == prefixsum.end())
            {
                prefixsum[sum] = i;
            }
        }
        return maxlen;
    }
};