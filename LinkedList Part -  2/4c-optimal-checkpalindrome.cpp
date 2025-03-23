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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reversehead(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *current = head;
        while (current != NULL)
        {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        // find the middle node or m1
        // reverse the second half
        // compare and then return
        // before returning reverse again as it changes the structure
        ListNode *first = head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) // condition for m1
        {
            slow = slow->next; // n/2 iterations
            fast = fast->next->next;
        }
        // m1 is slow
        ListNode *newhead = reversehead(slow->next); // n/2 iterations
        ListNode *second = newhead;
        while (second != NULL)
        {
            if (first->val != second->val)
            {
                reversehead(newhead); // n/2
                return false;
            }
            first = first->next;
            second = second->next; // n/2
        }
        reversehead(newhead);
        return true;
        // overall tc, sc == O(2n) , O(1)
    }
};