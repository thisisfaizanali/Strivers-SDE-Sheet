/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        // No need of Morris traversal
        // Utilize the property of BST :
        pre = nullptr; // candidate predecessor
        suc = nullptr; // candidate successor
        Node *curr = root;
        while (curr)
        {
            if (key > curr->key)
            {
                // largest smaller value (like BS)
                pre = curr;
                curr = curr->right;
            }
            else
                curr = curr->left;
        }
        curr = root;
        while (curr)
        {
            if (key < curr->key)
            {
                // smallest larger value (like BS)
                suc = curr;
                curr = curr->left;
            }
            else
                curr = curr->right;
        }
    }
};