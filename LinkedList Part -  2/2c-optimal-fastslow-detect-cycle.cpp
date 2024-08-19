/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma");
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
    bool hasCycle(ListNode *head)
    {
        // lets use fast and slow pointers
        // tortoise and hare method
        // intuition : slow -1 and fast -2
        // difference between fast and slow = d
        // d=d-1 always
        // so in a loop slow and fast are bound to overlap at some point
        if (head == NULL || head->next == nullptr)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != nullptr)
        {
            // O(n) and O(1)
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};