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
        // nth node from end
        // So, lengthNode - (n-1) node from starting
        // tc, sc = O(n) , O(1)
        if (head == NULL || head->next == nullptr)
        {
            return NULL;
        }
        int length = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        int nFromStart = length - (n - 1);
        if (nFromStart == 1)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        int counter = 0;
        temp = head;
        ListNode *prev = NULL;
        while (temp != NULL)
        {
            counter++;
            if (counter == nFromStart)
            {
                prev->next = prev->next->next;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};