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
    ListNode *helper(ListNode *temp, int k)
    {
        int count = 1;
        while (temp != NULL)
        {
            if (count == k)
            {
                return temp;
            }
            count++;
            temp = temp->next;
        }
        return temp;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        // tc, sc == (O(2n), O(1))
        if (head == 0 || k == 0)
            return head;
        // if k== length of ll
        // return head;
        // if k is very big
        // then no of rotations = k %length
        // so first lets find the length and tail
        int length = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            length++;
        }
        // edge case
        if (k % length == 0)
            return head;
        // effective number of operations to perform
        k %= length;

        tail->next = head;
        // step 3 :  find the (length -k) node
        ListNode *nthnode = helper(head, length - k);
        head = nthnode->next;
        nthnode->next = nullptr;
        return head;
    }
};
