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
    ListNode *middleNode(ListNode *head)
    {
        // no of nodes = n
        // if n is even -> n/2 , n/2 +1
        // if n is odd -> n+1/2
        int count = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int counter1 = 0;
        ListNode *ans;
        temp = head;
        while (temp != NULL)
        {
            counter1++;

            if (count & 1 && counter1 == (count + 1) / 2)
            {
                ans = temp;
            }
            else if (((count & 1) == 0) && counter1 == count / 2 + 1)
            {
                ans = temp;
            }
            temp = temp->next;
        }
        return ans;
    }
};