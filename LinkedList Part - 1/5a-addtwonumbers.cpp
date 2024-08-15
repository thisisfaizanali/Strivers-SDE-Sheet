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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // my brute solution memory limit was exceeded
        // whenever you have to generate a new list
        //  use a dummy node
        int carry = 0;
        ListNode *dummyNode = new ListNode();
        // for creation of new nodes, i used temp
        ListNode *temp = dummyNode;
        while (l1 != NULL || l2 != NULL || carry)
        // can use a separate if condition for carry
        // outside the while loop if carry> 0
        // make a new node and do the thing
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            temp->next = newNode;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};