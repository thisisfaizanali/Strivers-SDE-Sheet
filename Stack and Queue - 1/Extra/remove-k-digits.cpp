/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        stack<char> st;
        for (int i = 0; i < n; ++i)
        {
            // Remove digits from the stack if:
            // - The stack is not empty
            // - There are still digits left to remove (k > 0)
            // - The current digit is smaller than the top of the stack
            while (!st.empty() && k > 0 && num[i] < st.top()) // no equal sign
            {
                st.pop(); // Remove the top element to minimize the number
                k--;      // Decrement the count of digits to remove
            }
            st.push(num[i]); // Add the current digit to the stack
        }

        // Remove any remaining digits if k > 0
        while (k > 0 && !st.empty())
        {
            st.pop(); // Pop excess digits from the stack
            k--;
        }

        // Collect the digits from the stack into a result vector
        vector<char> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }

        // Reverse the result vector to form the correct number order
        reverse(result.begin(), result.end());
        string ans(result.begin(), result.end()); // Convert vector to string

        // Remove leading zeros -> edge case
        int start = 0;
        while (start < ans.size() && ans[start] == '0')
            start++;
        ans = ans.substr(start); // Keep the substring without leading zeros

        // If the result is empty (all digits removed), return "0"
        return ans.empty() ? "0" : ans; // edge case
    }
};