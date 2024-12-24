/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class MinStack
{
public:
    stack<long long> st;
    long long mini;
    MinStack()
    {
        while (!st.empty())
            st.pop(); // ensure the stack is empty
        mini = INT_MAX;
    }

    void push(int val)
    {
        long long value = val;
        if (st.empty())
        {
            st.push(value);
            mini = value;
        }
        else
        {
            // stack is not empty
            if (value < mini)
            {
                // push the transformed value to stack
                st.push(2 * value - mini);
                mini = value;
            }
            else
            {
                st.push(value);
            }
        }
    }

    void pop()
    {
        if (st.empty())
            return; // nothing to pop;
        long long el = st.top();
        st.pop();
        if (el < mini)
        {
            // this means we had a transformed value;
            // we need to readjust the value of minimum:
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
            return -1;
        long long el = st.top();
        if (el < mini)
        {
            // this means we tranformed values;
            return mini;
        }
        return el;
    }

    int getMin()
    {
        return mini;
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