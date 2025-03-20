/*++++++++++++++++++++++++++++++++++++++++++++++++++++++  Bismillah  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
int findCeil(Node *root, int input)
{
    // apply the principles of BS on arrays to here :
    // ceil = lower bound = smallest arr[mid] >= x :
    // here while condition is root and arr[mid] is root->data :
    if (root == NULL)
        return -1;
    int ans = -1;
    while (root)
    {
        if (root->data >= input)
        {
            ans = root->data;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return ans;
}
