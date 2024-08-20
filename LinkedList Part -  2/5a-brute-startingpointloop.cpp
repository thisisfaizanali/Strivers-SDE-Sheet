/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
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
    ListNode *detectCycle(ListNode *head)
    {
        // my brute force approach will be using hashing
        // tc, sc == O(n) , O(1)
        unordered_map<ListNode *, int> mpp;
        ListNode *temp = head;
        while (temp != NULL)
        {
            if (mpp.find(temp) != mpp.end())
            {
                return temp;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }
        return nullptr;
    }
};