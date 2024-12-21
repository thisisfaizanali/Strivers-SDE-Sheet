/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();

class MyStack
{
private:
    queue<int> q1, q2; // Two queues to simulate stack behavior

public:
    MyStack()
    {
        // Constructor: No specific initialization required
    }

    void push(int x)
    {
        // Always push to q1
        q1.push(x);
    }

    int pop()
    {
        if (q1.empty())
            return -1; // Edge case: Stack is empty

        // Move all elements except the last one to q2
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        // The last element in q1 is the top of the stack
        int topElement = q1.front();
        q1.pop();

        // Swap q1 and q2 for the next operation
        swap(q1, q2);

        return topElement;
    }

    int top()
    {
        if (q1.empty())
            return -1; // Edge case: Stack is empty

        // Move all elements except the last one to q2
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        // The last element in q1 is the top of the stack
        int topElement = q1.front();

        // Push it to q2 as well
        q2.push(topElement);
        q1.pop();

        // Swap q1 and q2 for the next operation
        swap(q1, q2);

        return topElement;
    }

    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
