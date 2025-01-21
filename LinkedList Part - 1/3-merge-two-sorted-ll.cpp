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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // similar to merge step method of arrays but adapt to ll :
        //  Edge case : if any ll is empty, return the other one
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        // When merging or creating a new ll : use dummy node
        ListNode *dummyhead = new ListNode(-1);
        // pointer for traversal : curr
        ListNode *curr = dummyhead;
        // two pointer approach of merging (from arrays)
        ListNode *p1 = list1;
        ListNode *p2 = list2;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val <= p2->val)
            {
                curr->next = p1;
                p1 = p1->next;
            }
            else
            {
                curr->next = p2;
                p2 = p2->next;
            }
            // very important : (because of dummy node)
            curr = curr->next; // curr should be the last node in the merge list
        }
        // Leftover elements : any one ll will get finished :
        // curr is the last node so :
        if (p1 != nullptr)
        {
            curr->next = p1;
        }
        if (p2 != nullptr)
        {
            curr->next = p2;
        }
        // as dummyhead->next is the real head/ans :
        return dummyhead->next;
    }
};