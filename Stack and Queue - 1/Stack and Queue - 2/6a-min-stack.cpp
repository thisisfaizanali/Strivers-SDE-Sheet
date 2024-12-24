/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class MinStack
{
    // this is the pair solution
    // constant and space - 2n
    stack<pair<int, int>> st;
    // value and min
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            int currMin = st.top().second;
            st.push({val, min(val, currMin)});
        }
    }

    void pop()
    {
        if (!st.empty())
            st.pop();
    }

    int top()
    {
        if (!st.empty())
        {
            return st.top().first;
        }
        return -1;
    }

    int getMin()
    {
        if (!st.empty())
            return st.top().second;
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */