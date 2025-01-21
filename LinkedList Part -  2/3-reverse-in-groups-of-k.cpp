/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
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
    int getlength(ListNode *head)
    {
        int length = 0;
        while (head != nullptr)
        {
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // striver code is shitty
        // in leetcode : remaining nodes are as it is
        // in gfg : they are also reversed
        if (head == nullptr)
            return head;
        ListNode *curr = head;        // pointer for traversal
        ListNode *newhead = nullptr;  // newhead of ll
        ListNode *tail = nullptr;     // tail of ll
        int length = getlength(head); // length of ll
        while (curr != nullptr)
        {
            // if remaining nodes < k : connect as is
            if (length < k)
            {
                if (tail != nullptr)
                {
                    tail->next = curr;
                }
                break;
            }
            ListNode *grouphead = curr; // head of current group
            ListNode *prev = nullptr;
            ListNode *nextnode = nullptr;
            int count = 0; // reset for new group
            // reverse the current group : same process just count<k condition is there :
            while (curr != nullptr && count < k)
            {
                nextnode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextnode;
                count++;
            }
            // if first group :
            if (newhead == nullptr)
            {
                newhead = prev;
            }
            // if not first group :
            if (tail != nullptr)
            {
                tail->next = prev;
            }
            // the tail of current group is the original head of the group :
            tail = grouphead;
            length -= k; // reduce length by k
        }
        return newhead;
    }
};