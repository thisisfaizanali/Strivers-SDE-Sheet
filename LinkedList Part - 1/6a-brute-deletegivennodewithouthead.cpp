#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        // head will not be given
        // not a tail node
        // A dumb problem with a dumb solution
        // Hint in desc : Note that by deleting the node, we do not mean removing it from memory
        node->val = node->next->val;
        node->next = node->next->next;
    }
};