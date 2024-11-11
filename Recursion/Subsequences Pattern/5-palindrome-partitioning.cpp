/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans; // will hold the answer
        vector<string> ds;          // ds needed
        solve(0, s, ds, ans);       // recursive function
        return ans;
    }
    void solve(int idx, string s, vector<string> &ds, vector<vector<string>> &ans)
    {
        if (idx >= s.size())
        {
            // base case
            ans.push_back(ds);
            return;
        }
        for (int i = idx; i < s.size(); ++i)
        {
            if (isPalindrome(s, idx, i))
            {
                // condition check
                ds.push_back(s.substr(idx, i - idx + 1)); // main code
                solve(i + 1, s, ds, ans);
                ds.pop_back(); // back track
            }
        }
    }
    bool isPalindrome(string s, int start, int end)
    {
        // condition checker
        while (start <= end)
        {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
