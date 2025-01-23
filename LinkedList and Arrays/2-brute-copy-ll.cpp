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
        if (!head)
            return nullptr;
        // map original node with created nodes :
        unordered_map<Node *, Node *> mpp;
        Node *curr = head;
        while (curr != nullptr)
        {
            mpp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        // set the next and random pointers :
        // mpp[curr] points to the deep copy :
        curr = head;
        while (curr != nullptr)
        {
            mpp[curr]->next = mpp[curr->next];
            mpp[curr]->random = mpp[curr->random];
            curr = curr->next;
        }
        return mpp[head];
    }
};