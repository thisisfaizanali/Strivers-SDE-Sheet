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
    int isSumProperty(Node *root)
    {
        // empty tree follows the property :
        if (!root)
            return 1;
        // leaf nodes follow the property :
        if (!root->left && !root->right)
            return 1;
        int leftData = root->left ? root->left->data : 0;
        int rightData = root->right ? root->right->data : 0;
        if (root->data != leftData + rightData)
            return 0;
        // go left right and come back
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};