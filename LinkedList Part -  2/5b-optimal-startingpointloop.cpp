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
        // my optimal approach will try to make sc == O(1)
        // using slow and fast pointers
        if (head == NULL || head->next == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != nullptr)
        {

            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                // this if condition only checks the presence of a cycle
                // not necessarily returns the starting point
                ListNode *temp = head;
                while (temp != slow)
                {
                    temp = temp->next;
                    slow = slow->next; // most crucial thing
                    // watch striver video again you will understand
                }
                return temp;
            }
        }
        return nullptr;
    }
};