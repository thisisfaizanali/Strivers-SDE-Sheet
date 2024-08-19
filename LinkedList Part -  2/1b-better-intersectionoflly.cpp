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
        // let's use hashing
        // store nodes instead of values
        unordered_map<ListNode *, int> mpp;
        ListNode *temp1 = headA;
        while (temp1 != NULL)
        {
            mpp[temp1] = 1;
            temp1 = temp1->next;
        }
        temp1 = headB;
        while (temp1 != NULL)
        {
            if (mpp.find(temp1) != mpp.end())
            {
                return temp1;
            }
            temp1 = temp1->next;
        }
        return NULL;
    }
};