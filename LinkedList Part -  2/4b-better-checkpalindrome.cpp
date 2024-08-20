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
    bool isPalindrome(ListNode *head)
    {
        // we can use a stack to compare because
        // of its LIFO nature
        // space comp == O(n)
        // tc == O(2n)
        stack<int> stk;
        ListNode *temp = head;
        while (temp != NULL)
        {
            stk.push(temp->val);
            temp = temp->next;
        }

        temp = head;

        while (temp != NULL)
        {
            if (stk.top() != temp->val)
            {
                return false;
            }
            stk.pop();
            temp = temp->next;
        }
        return true;
    }
};