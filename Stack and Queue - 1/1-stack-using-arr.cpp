/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr; }();
class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

void MyStack ::push(int x)
{
    if (top >= 999)
    {
        return;
    }
    arr[++top] = x;
}

int MyStack ::pop()
{
    if (top < 0)
    {
        return -1;
    }
    return arr[top--];
}