/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        stack<char> st;
        for (auto x : s)
        {
            if (x == '(' || x == '{' || x == '[') // open brackets
            {
                st.push(x);
            }
            else // means other characters
            {
                if (st.empty()) // nothing to match
                    return false;
                char top = st.top();
                if (x == ')' && top == '(' || x == '}' && top == '{' || x == ']' && top == '[')
                    st.pop(); // match
                else
                    return false; // mismatch
            }
        }
        return st.empty(); // true if stack is empty
    }
};