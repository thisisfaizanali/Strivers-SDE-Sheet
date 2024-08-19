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
    ListNode *ans(ListNode *smallhead, ListNode *bighead, int d)
    {
        while (d)
        {
            d--;
            bighead = bighead->next;
        }
        while (smallhead != bighead)
        {
            smallhead = smallhead->next;
            bighead = bighead->next;
        }
        return smallhead;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // this is bit better
        // we will start to find the common node
        // at the same vertical level of the lists
        // tc and sc = o(n1 + 2n2) , o(1)
        int len1 = 0, len2 = 0;
        ListNode *temp = headA;
        while (temp != NULL)
        {
            len1++;
            temp = temp->next;
        }
        temp = headB;
        while (temp != NULL)
        {
            len2++;
            temp = temp->next;
        }
        if (len1 < len2)
        {
            return ans(headA, headB, len2 - len1);
        }
        else
            return ans(headB, headA, len1 - len2);
    }
};