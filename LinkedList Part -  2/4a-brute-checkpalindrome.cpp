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
        ListNode *current = head; // n, 1 == complexity
        ListNode *prev = NULL;
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
    { // overall tc, sc == O(3n) , O(n)
        // if we get the same list on reversing
        // it is a palindrome
        // we have to make a copy list
        // in order to prevent tampering with the orignal
        ListNode *t1 = head;      // original
        ListNode *t3 = nullptr;   // dummy head
        ListNode *tail = nullptr; // for tail of new list
        while (t1 != NULL)
        {
            ListNode *newNode = new ListNode(t1->val);
            if (t3 == nullptr)
            {
                t3 = newNode;
                tail = t3;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
            t1 = t1->next;
        }

        ListNode *t2 = reversehead(t3);

        t1 = head;
        while (t2 != NULL)
        {
            if (t1->val != t2->val)
                return false;
            t1 = t1->next;
            t2 = t2->next;
        }
        return true;
    }
};