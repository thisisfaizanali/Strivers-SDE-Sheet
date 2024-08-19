#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        // O(n1+n2)
        // slightly optimized than last
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        while (t1 != t2) // what if theres only one list
        {
            t1 = t1->next;
            t2 = t2->next;

            if (t1 == t2)
                return t1;

            if (t1 == NULL)
                t1 = headB; // do dry run, the proof is easy for this method

            if (t2 == NULL)
                t2 = headA;
        }
        return t1;
    }
};