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
        // space complexity : O(n)
        // Time Complexity: O(N * 2 * log(N) )
        //  i am going to use hashing approach
        if (head == NULL)
            return false;
        unordered_map<ListNode *, int> mpp;
        ListNode *temp1 = head;
        while (temp1 != NULL)
        {
            // first check then mark visit
            if (mpp.find(temp1) != mpp.end())
            {
                return true;
            }
            mpp[temp1] = 1;
            temp1 = temp1->next;
        }
        return false;
    }
};