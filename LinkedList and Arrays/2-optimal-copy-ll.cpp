/*+++++++++++++++++++++++++++++++   Bismillah   ++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
static auto _ = []()
{ios::sync_with_stdio(false); cin.tie(nullptr); return nullptr; }();
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // striver code is weird :
        if (!head)
            return nullptr;
        // Step 1: Insert cloned nodes directly after the corresponding original nodes
        Node *curr = head;
        while (curr)
        {
            Node *newnode = new Node(curr->val);
            newnode->next = curr->next;
            curr->next = newnode;
            curr = newnode->next;
        }
        curr = head;
        // Step 2: Set the random pointers of the cloned nodes :
        while (curr)
        {
            if (curr->random)
            {
                // confusing -> use pen and paper :
                // curr->next is copied node whose random = copy of original random
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // Step 3: Separate the original list and the cloned list :
        Node *newhead = head->next; // copied ll head
        Node *copy = newhead;       // for traversing copied ll
        curr = head;                // for traversing original ll
        while (curr)
        {
            // Restore the original node's next pointer to skip the cloned node
            curr->next = curr->next->next;
            // Restore the original node's next pointer to skip the cloned node
            if (copy->next)
                copy->next = copy->next->next;
            // move the pointers :
            curr = curr->next;
            copy = copy->next;
        }
        // head of cloned list :
        return newhead;
    }
};