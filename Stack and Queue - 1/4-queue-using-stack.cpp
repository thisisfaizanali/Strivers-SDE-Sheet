/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

class MyQueue
{
private:
    stack<int> s1, s2; // Two stacks for simulating a queue

public:
    MyQueue()
    {
        // Constructor: No specific initialization required
    }

    void push(int x)
    {
        // Push element onto stack s1
        s1.push(x);
    }

    int pop()
    {
        // If s2 is empty, transfer elements from s1 to s2
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // The top of s2 is the front of the queue
        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek()
    {
        // If s2 is empty, transfer elements from s1 to s2
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // The top of s2 is the front of the queue
        return s2.top();
    }

    bool empty()
    {
        // Queue is empty if both stacks are empty
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
