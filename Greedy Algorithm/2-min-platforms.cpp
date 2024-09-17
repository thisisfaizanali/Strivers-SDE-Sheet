#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();
        // since the arr and dep are not mapped/ordered
        // together for a single train
        // no need for struct
        // can be sorted independently
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int count = 1; // to keep track of current no of platforms
        int ans = 1;   // this will be the max val of count recorded

        // let us use two pointer approach
        int i = 1; // because i=0 is already covered by count & ans=1
        int j = 0;
        while (i < n && j < n)
        {
            if (arr[i] <= dep[j]) // gaadi khulne ke pahle ek aur gaadi aa gayi
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};