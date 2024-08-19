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
        // this code will either fail with tle
        // or will fail at test case 15
        if (head == NULL || head->next == nullptr) // Handle empty or single-node list
            return false;

        ListNode *temp1 = head;
        while (temp1 != nullptr)
        {
            ListNode *temp2 = temp1->next;
            while (temp2 != nullptr)
            {
                if (temp2 == temp1)
                {
                    return true; // Cycle detected
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }

        return false; // No cycle detected
    }
};
