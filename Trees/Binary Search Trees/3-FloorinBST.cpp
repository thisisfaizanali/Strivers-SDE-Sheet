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
class Solution
{
public:
    int floor(Node *root, int x)
    {
        // apply the principles of BS on arrays to here :
        // floor is largest arr[mid] <= x :
        // here while condition is root and arr[mid] is root->data :
        int ans = -1;
        while (root)
        {
            if (root->data <= x)
            {
                ans = root->data;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        return ans;
    }
};