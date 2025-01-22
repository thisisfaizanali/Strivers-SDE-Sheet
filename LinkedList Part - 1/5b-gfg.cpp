/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *curr = head;
        Node *prev = nullptr, *nextnode = nullptr;
        while (curr != nullptr)
        {
            nextnode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextnode;
        }
        return prev;
    }
    Node *addTwoLists(Node *num1, Node *num2)
    {
        // this problem is a better version than leetcode one for concept :
        //  for main code to work the original ll must be reversed :
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node *dummy = new Node(-1);
        Node *curr = dummy;
        long long carry = 0;
        while (num1 != nullptr || num2 != nullptr || carry != 0)
        {
            long long sum = carry;
            if (num1 != nullptr)
            {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2 != nullptr)
            {
                sum += num2->data;
                num2 = num2->next;
            }
            carry = sum / 10;
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }
        Node *newhead = reverse(dummy->next); // result should also be reversed
        // remove leading zeroes :
        while (newhead != nullptr && newhead->data == 0)
        {
            Node *temp = newhead;
            newhead = newhead->next;
            delete temp;
        }
        return (newhead == nullptr) ? new Node(0) : newhead;
    }
};