#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        // brute force approach
        // additional data structure stack is used because of LIFO
        ListNode *temp = head;
        stack<long long> stk;
        while (temp != NULL)
        {
            stk.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            temp->val = stk.top();
            stk.pop();
            temp = temp->next;
        }
        return head;
    }
};