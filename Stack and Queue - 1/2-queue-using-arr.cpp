/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr; }();
class MyQueue
{
private:
    int arr[100005];
    int front;
    int rear;

public:
    MyQueue()
    {
        front = 0;
        rear = 0;
    }
    void push(int);
    int pop();
};
void MyQueue ::push(int x)
{
    // inserting x in the queue at rear.
    arr[rear++] = x;
}

// Function to pop an element from queue and return that element.
int MyQueue ::pop()
{
    // if front is equal to rear, queue is empty.
    if (front == rear)
        return -1;

    // else we return the element at front.
    return arr[front++];
}
