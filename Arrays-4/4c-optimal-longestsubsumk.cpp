class Solution
{
public:
    int maxLen(vector<int> &arr, int n)
    {
        // Your code here
        int maxlen = 0;
        long long k; // required sum
        // use two pointers
        // O(2n) tc and sc O(n)
        int left = 0;
        int right = 0;
        long long sum = arr[0];
        while (right < n)
        {
            while (left <= right && sum > k)
            {
                sum -= arr[left];
                left++;
            }
            if (sum == k)
            {
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
            if (right < n)
                sum += arr[right];
        }
        return maxlen;
    }
};