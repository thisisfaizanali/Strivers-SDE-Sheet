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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // tc , sc = O(n), O(1)
        ListNode *slow = head;
        ListNode *fast = head;
        for (int i = 0; i < n; ++i)
        {
            fast = fast->next;
        }
        if (fast == NULL)
        {
            // first element from left is to be deleted
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while (fast->next != nullptr)
        {
            // linked list mein while conditions
            // bohot mera dimag kharab karte hain
            fast = fast->next;
            slow = slow->next;
        }
        // slow will be at that element and fast at last
        ListNode *x = slow->next;
        slow->next = slow->next->next;
        delete x;
        return head;
    }
};